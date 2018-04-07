package com.alan.alanjni;

import com.alan.alanjni.beans.ArgInfo;

/**
 * Author: AlanWang.
 * Date: 18/3/26 15:18.
 * Mail: alanwang6584@gmail.com
 */

public class JNIWrapper {
    /**
     * 底层的成功码，如果返回码不为该值，说明调用出错
     */
    private static final int SUCCESS_CODE = 0;


    // Used to load the 'alanjni' library on application startup.
    static {
        System.loadLibrary("alanjni");
    }


    /******************************************************************
     *  java 接口，调用底层接口向底层传递基本数据类型
     *****************************************************************/

    /**
     * 调用底层 nativeSetArgBoolean 接口
     * @param bRrg
     * @return
     */
    public boolean setArgBoolean(boolean bRrg) {
        return nativeSetArgBoolean(bRrg);
    }

    /**
     * 调用底层 nativeSetArgByte 接口
     * @param bArg
     * @return
     */
    public byte setArgByte(byte bArg) {
        return nativeSetArgByte(bArg);
    }

    /**
     * 调用底层 nativeSetArgChar 接口
     * @param cArg
     * @return
     */
    public char setArgChar(char cArg) {
        return nativeSetArgChar(cArg);
    }

    /**
     * 调用底层 nativeSetArgShort 接口
     * @param sArg
     * @return
     */
    public short setArgShort(short sArg) {
        return nativeSetArgShort(sArg);
    }

    /**
     * 调用底层 nativeSetArgInt 接口，如果参数错误或执行错误，则向调用者抛出异常
     * @param iArg
     * @throws RuntimeException
     */
    public void setArgInt(int iArg) throws RuntimeException {
        if (iArg < 0) {
            throw new IllegalArgumentException("Invalid argument when call setArgInt.");
        }
        int errCode = nativeSetArgInt(iArg);
        if (SUCCESS_CODE != errCode) {
            throw new RuntimeException("Error during setArgInt.");//一般这里可以是自定义异常
        }
    }

    /**
     * 调用底层 nativeSetArgShort 接口
     * @param lArg
     * @return
     */
    public long setArgLong(long lArg) {
        return nativeSetArgLong(lArg);
    }

    /**
     * 调用底层 nativeSetArgFloat 接口
     * @param fArg
     * @return
     */
    public float setArgFloat(float fArg) {
        return nativeSetArgFloat(fArg);
    }

    /**
     * 调用底层 nativeSetArgDouble 接口
     * @param dArg
     * @return
     */
    public double setArgDouble(double dArg) {
        return nativeSetArgDouble(dArg);
    }

    //////////////////////////////////////////////////////////////////////


    /******************************************************************
     *  java 接口，调用底层接口向底层传递对象数据类型
     *****************************************************************/

    /**
     * 调用底层 nativeSetArgString 接口
     * @param strArg
     */
    public String setArgString(String strArg) {
        return nativeSetArgString(strArg);
    }

    /**
     * 调用底层 nativeSetArgFieldInfo 接口，底层通过 fieldId 来获取对象的属性数据
     * @param argInfo
     */
    public void setArgFieldInfo(ArgInfo argInfo) {
        nativeSetArgFieldInfo(argInfo);
    }

    //////////////////////////////////////////////////////////////////////


    /******************************************************************
     *  向底层传递基本数据类型，以及底层向上层返回基本数据类型
     *****************************************************************/
    /**
     * 向底层传递 boolean 型参数，并返回 boolean 型返回值
     * @param bArg
     * @return
     */
    private native boolean nativeSetArgBoolean(boolean bArg);

    /**
     * 向底层传递 byte 型参数，并返回 byte 型返回值
     * @param bArg
     * @return
     */
    private native byte nativeSetArgByte(byte bArg);

    /**
     * 向底层传递 char 型参数，并返回 char 型返回值
     * @param cArg
     * @return
     */
    private native char nativeSetArgChar(char cArg);

    /**
     * 向底层传递 short 型参数，并返回 short 型返回值
     * @param sArg
     * @return
     */
    private native short nativeSetArgShort(short sArg);

    /**
     * 向底层传递 int 型参数，并返回 int 型返回值
     * @param iArg
     * @return
     */
    private native int nativeSetArgInt(int iArg);

    /**
     * 向底层传递 long 型参数，并返回 long 型返回值
     * @param lArg
     * @return
     */
    private native long nativeSetArgLong(long lArg);

    /**
     * 向底层传递 float 型参数，并返回 float 型返回值
     * @param fArg
     * @return
     */
    private native float nativeSetArgFloat(float fArg);

    /**
     * 向底层传递 float 型参数，并返回 float 型返回值
     * @param dArg
     * @return
     */
    private native double nativeSetArgDouble(double dArg);

    //////////////////////////////////////////////////////////////////////


    /******************************************************************
     *  向底层传递对象数据类型
     *****************************************************************/
    /**
     * 向底层传递 String 类型参数
     * @param str
     */
    private native String nativeSetArgString(String str);

    /**
     * 向底层传递自定义对象
     * @param argInfo
     */
    private native void nativeSetArgFieldInfo(ArgInfo argInfo);
}
