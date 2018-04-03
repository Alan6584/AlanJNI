package com.alan.alanjni.beans;

/**
 * Author: AlanWang.
 * Date: 18/4/2 07:54.
 * Mail: alanwang6584@gmail.com
 */

public class ArgFieldInfo {
    /**
     * boolean 型属性变量
     */
    private boolean booleanArg;

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

    public boolean isBooleanArg() {
        return booleanArg;
    }

    public void setBooleanArg(boolean booleanArg) {
        this.booleanArg = booleanArg;
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
                "booleanArg=" + booleanArg +
                ", intArg=" + intArg +
                ", longArg=" + longArg +
                ", floatArg=" + floatArg +
                ", doubleArg=" + doubleArg +
                '}';
    }
}
