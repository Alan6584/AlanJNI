package com.alan.alanjni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = MainActivity.class.getSimpleName();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        jniTest();

    }

    private void jniTest() {
        JNIWrapper jniWrapper = new JNIWrapper();

        boolean bRet = jniWrapper.setArgBoolean(false);
        Log.e(TAG, "setArgBoolean()--->>>bRet = " + bRet);

        byte byArg = 0x02;
        byte byRet = jniWrapper.setArgByte(byArg);
        Log.e(TAG, "setArgByte()--->>>byRet = " + byRet);

        char cArg = 'a';
        char cRet = jniWrapper.setArgChar(cArg);
        Log.e(TAG, "setArgChar()--->>>cRet = " + cRet);

        short sArg = 2;
        short sRet = jniWrapper.setArgShort(sArg);
        Log.e(TAG, "setArgShort()--->>>sRet = " + sRet);

        int iArg = 2;
        try {
            jniWrapper.setArgInt(sArg);
        } catch (RuntimeException e) {
            e.printStackTrace();
        }

        long lArg = System.currentTimeMillis();
        long lRet = jniWrapper.setArgLong(lArg);
        Log.e(TAG, "setArgLong()--->>>lArg = " + lArg + "--->>lRet = " + lRet);

        float fArg = 1.0f;
        float fRet = jniWrapper.setArgFloat(fArg);
        Log.e(TAG, "setArgFloat()--->>>fArg = " + fArg + "--->>fRet = " + fRet);

        double dArg = 1.0f;
        double dRet = jniWrapper.setArgDouble(dArg);
        Log.e(TAG, "setArgDouble()--->>>dArg = " + dArg + "--->>dRet = " + dRet);
    }
}
