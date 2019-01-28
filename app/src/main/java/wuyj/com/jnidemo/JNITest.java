package wuyj.com.jnidemo;

import android.util.Log;

/**
 * author: wuyoujian
 * Date: 2019/1/18
 */
public class JNITest {
    static {
        System.loadLibrary("JNITest");
    }
    public native String get();

    // C调用java空方法
    public void helloFromJava() {
        Log.d("JNITest","helloFromJava1111");
    }

    // C调用java中的带两个int参数的方法
    public int Add(int x, int y) {
        int result = 100*(x + y);
        Log.d("JNITest","java result=" + result);
        return result;
    }

    // C调用java中参数为string的方法
    public void printString(String s) {
        Log.d("JNITest","java " + s);
    }

    //静态方法
    public static void printStaticStr(String s) {
        Log.d("JNITest","java static->>>>>> " + s);
    }

    // 让c代码调用对应的java代码
    public native void callHelloFromJava();
    public native void callAdd();
    public native void callPrintString();

    // 调用一个静态的c代码
    public native void callPrintStaticStr();
}
