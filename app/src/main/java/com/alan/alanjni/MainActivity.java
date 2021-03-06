package com.alan.alanjni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import com.alan.alanjni.beans.ArgInfo;
import com.alan.alanjni.beans.OtherInfo;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = MainActivity.class.getSimpleName();

    private JNIWrapper jniWrapper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        jniWrapper = new JNIWrapper();

//        jniTest01();
        jniTest02();

    }

    /**
     * 向底层传递对象类型数据
     */
    private void jniTest02() {
        String strRet = jniWrapper.setArgString("this is string arg from java!");
        Log.e(TAG, "setArgString()--->>>strRet = " + strRet);

        ArgInfo argInfo = new ArgInfo();
        argInfo.setByteArg((byte) 0x02);
        argInfo.setBooleanArg(true);
        argInfo.setCharArg('a');
        argInfo.setShortArg((short) 6);
        argInfo.setIntArg(2);
        argInfo.setLongArg(32 * 1000 * 1000L);
        argInfo.setFloatArg(1.2f);
        argInfo.setDoubleArg(3.3);
        argInfo.setStrArg("string argument");

        OtherInfo otherInfo = new OtherInfo(3);
        argInfo.setInfoArg(otherInfo);
        Log.e(TAG, "java set--->>>argInfo = " + argInfo);

        Log.e(TAG, "java setArgFieldInfo()------>>>");
        jniWrapper.setArgFieldInfo(argInfo);

        Log.e(TAG, "java setArgMethodInfo()------>>>");
        jniWrapper.setArgMethodInfo(argInfo);
    }


    /**
     * 测试向底层传递基本类型数据
     */
    private void jniTest01() {

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
