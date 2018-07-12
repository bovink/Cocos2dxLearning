package org.cocos2dx.cpp;

import android.media.MediaPlayer;
import android.os.Environment;
import android.util.Log;

import java.io.File;
import java.io.IOException;

/**
 * @author bovink
 * @since 2018/7/12
 */
public class RecordHelper {

    private static RecordWavMaster master;
    private static MediaPlayer player;
    private static final String rootPath = Environment.getExternalStorageDirectory() + File.separator + "AudioRecord/";
    public RecordHelper() {

        master = new RecordWavMaster();
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
}
