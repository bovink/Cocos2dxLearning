package org.cocos2dx.cpp;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;

import com.bovink.cocos2dxlearning.R;

/**
 * @author bovink
 * @since 2018/7/21
 */
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.act_main);
    }
}
