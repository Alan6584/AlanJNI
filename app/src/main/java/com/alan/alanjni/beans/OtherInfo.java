package com.alan.alanjni.beans;

/**
 * Author: wangjianjun.
 * Date: 18/4/7 18:13.
 * Mail: alanwang6584@gmail.com
 */

public class OtherInfo {

    private int intInfo;

    public OtherInfo() {
    }

    public OtherInfo(int intInfo) {
        this.intInfo = intInfo;
    }

    public int getIntInfo() {
        return intInfo;
    }

    public void setIntInfo(int intInfo) {
        this.intInfo = intInfo;
    }

    @Override
    public String toString() {
        return "OtherInfo{" +
                "intInfo=" + intInfo +
                '}';
    }
}
