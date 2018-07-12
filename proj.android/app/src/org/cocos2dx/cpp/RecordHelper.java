package org.cocos2dx.cpp;

import android.media.MediaPlayer;
import android.os.AsyncTask;
import android.os.Environment;
import android.util.Log;

import org.cocos2dx.lib.Cocos2dxActivity;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.lang.ref.WeakReference;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

import edu.cmu.pocketsphinx.Assets;
import edu.cmu.pocketsphinx.Config;
import edu.cmu.pocketsphinx.Decoder;
import edu.cmu.pocketsphinx.Hypothesis;
import edu.cmu.pocketsphinx.Segment;
import edu.cmu.pocketsphinx.SpeechRecognizer;
import edu.cmu.pocketsphinx.SpeechRecognizerSetup;

/**
 * @author bovink
 * @since 2018/7/12
 */
public class RecordHelper {
    private static Cocos2dxActivity mCocos2dxActivity;

    private static RecordWavMaster master;
    private static MediaPlayer player;
    private static final String rootPath = Environment.getExternalStorageDirectory() + File.separator + "AudioRecord/";

    private static SpeechRecognizer recognizer;

    public RecordHelper() {

        master = new RecordWavMaster();

        RecordHelper.mCocos2dxActivity = (Cocos2dxActivity) Cocos2dxActivity.getContext();

        new SetupTask(this).execute();
    }

    public static void startRecord() {

        master.recordWavStart();
    }

    public static void stopRecord() {

        master.recordWavStop();
    }


    /**
     * 播放音频
     */
    public static void playAudio() {
        String path = rootPath + "audio.wav";
        try {

            if (player != null && player.isPlaying()) {
                player.stop();
                player.reset();
            }
            if (player == null) {
                player = new MediaPlayer();
            }

            player.setDataSource(path);
            player.prepare();
            player.start();
            player.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {

                @Override
                public void onCompletion(MediaPlayer mp) {
                    Log.e("audio", "end");
                    player.release();
                    player = null;
                }

            });
            player.setLooping(false);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public static void process() {

        try {

            String path = rootPath + "audio.wav";

            Assets assets = new Assets(mCocos2dxActivity);
            File assetDir = assets.syncAssets();

            Config c;
            c = Decoder.defaultConfig();
            c.setString("-hmm", new File(assetDir, "en-us-ptm").getAbsolutePath());
            c.setString("-dict", new File(assetDir, "cmudict-en-us.dict").getAbsolutePath());
            c.setString("-kws", new File(assetDir, "digits.gram").getAbsolutePath());

            Decoder d;
            d = new Decoder(c);

            FileInputStream fis = new FileInputStream(path);

            d.startUtt();
            byte[] b = new byte[4096];
            try {
                int nbytes;
                while ((nbytes = fis.read(b)) >= 0) {
                    ByteBuffer bb = ByteBuffer.wrap(b, 0, nbytes);

                    // Not needed on desktop but required on android
                    bb.order(ByteOrder.LITTLE_ENDIAN);

                    short[] s = new short[nbytes / 2];
                    bb.asShortBuffer().get(s);
                    d.processRaw(s, nbytes / 2, false, false);
                }
            } catch (IOException e) {
            }
            d.endUtt();

            Hypothesis hypothesis = d.hyp();
            if (hypothesis != null) {
                String hypstr = hypothesis.getHypstr();
                int hypothesisProb = hypothesis.getProb();
                int bestScore = hypothesis.getBestScore();
                System.out.println("hypstr = " + hypstr);
                System.out.println("hypothesisProb = " + hypothesisProb);
                System.out.println("bestScore = " + bestScore);

                StringBuilder sb = new StringBuilder();
                for (Segment seg : d.seg()) {

                    String word = seg.getWord();
                    int aScore = seg.getAscore();
                    int lScore = seg.getLscore();
                    int prob = seg.getProb();
                    double prob_exp = d.getLogmath().exp(prob);
                    System.out.println("word = " + word);
                    System.out.println("aScore = " + aScore);
                    System.out.println("lScore = " + lScore);
                    System.out.println("prob = " + prob);
                    System.out.println("prob_exp = " + prob_exp);
                    sb.append(word)
                            .append(" 匹配率:")
                            .append(prob_exp)
                            .append("\n");

                }
                recognizer.stop();
                System.out.println("sb.toString() = " + sb.toString());

            } else {
                System.out.println("不匹配");
            }
        } catch (IOException e) {
            e.printStackTrace();

        }
    }

    private static class SetupTask extends AsyncTask<Void, Void, Exception> {
        WeakReference<RecordHelper> activityReference;

        SetupTask(RecordHelper activity) {
            this.activityReference = new WeakReference<>(activity);
        }

        @Override
        protected Exception doInBackground(Void... params) {
            try {
                Assets assets = new Assets(mCocos2dxActivity);
                File assetDir = assets.syncAssets();
                activityReference.get().setupRecognizer(assetDir);
            } catch (IOException e) {
                return e;
            }
            return null;
        }

        @Override
        protected void onPostExecute(Exception result) {

        }
    }

    private void setupRecognizer(File assetsDir) throws IOException {
        // The recognizer can be configured to perform multiple searches
        // of different kind and switch between them

        recognizer = SpeechRecognizerSetup.defaultSetup()
                .setAcousticModel(new File(assetsDir, "en-us-ptm"))
                .setDictionary(new File(assetsDir, "cmudict-en-us.dict"))

                .setRawLogDir(assetsDir) // To disable logging of raw audio comment out this call (takes a lot of space on the device)
                .setSampleRate(16000)


                .getRecognizer();

    }
}
