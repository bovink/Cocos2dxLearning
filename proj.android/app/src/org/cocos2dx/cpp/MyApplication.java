package org.cocos2dx.cpp;

import android.app.Application;

import com.tencent.bugly.crashreport.CrashReport;

/**
 * @author bovink
 * @since 2018/9/26
 */
public class MyApplication extends Application {

    @Override
    public void onCreate() {
        super.onCreate();

        CrashReport.initCrashReport(getApplicationContext(), "3a223c7d72", true);
//        CrashReport.testJavaCrash();
    }
}
