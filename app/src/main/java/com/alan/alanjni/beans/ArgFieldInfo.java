package com.alan.alanjni.beans;

/**
 * Author: AlanWang.
 * Date: 18/4/2 07:54.
 * Mail: alanwang6584@gmail.com
 */

public class ArgFieldInfo {

    /**
     * byte 型属性变量
     */
    private byte byteArg;

    /**
     * boolean 型属性变量
     */
    private boolean booleanArg;

    /**
     * char 型属性变量
     */
    private char charArg;

    /**
     * short 型属性变量
     */
    private short shortArg;

    /**
     * int 型属性变量
     */
    private int intArg;

    /**
     * long 型属性变量
     */
    private long longArg;

    /**
     * float 型属性变量
     */
    private float floatArg;

    /**
     * double 型属性变量
     */
    private double doubleArg;


    public byte getByteArg() {
        return byteArg;
    }

    public void setByteArg(byte byteArg) {
        this.byteArg = byteArg;
    }

    public boolean isBooleanArg() {
        return booleanArg;
    }

    public void setBooleanArg(boolean booleanArg) {
        this.booleanArg = booleanArg;
    }

    public char getCharArg() {
        return charArg;
    }

    public void setCharArg(char charArg) {
        this.charArg = charArg;
    }

    public short getShortArg() {
        return shortArg;
    }

    public void setShortArg(short shortArg) {
        this.shortArg = shortArg;
    }

    public int getIntArg() {
        return intArg;
    }

    public void setIntArg(int intArg) {
        this.intArg = intArg;
    }

    public long getLongArg() {
        return longArg;
    }

    public void setLongArg(long longArg) {
        this.longArg = longArg;
    }

    public float getFloatArg() {
        return floatArg;
    }

    public void setFloatArg(float floatArg) {
        this.floatArg = floatArg;
    }

    public double getDoubleArg() {
        return doubleArg;
    }

    public void setDoubleArg(double doubleArg) {
        this.doubleArg = doubleArg;
    }

    @Override
    public String toString() {
        return "ArgFieldInfo{" +
                "byteArg=" + byteArg +
                ", booleanArg=" + booleanArg +
                ", charArg=" + charArg +
                ", shortArg=" + shortArg +
                ", intArg=" + intArg +
                ", longArg=" + longArg +
                ", floatArg=" + floatArg +
                ", doubleArg=" + doubleArg +
                '}';
    }
}
