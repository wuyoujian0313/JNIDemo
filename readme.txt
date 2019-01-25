1、创建调用so文件的java类，例如：
public class JNITest {
    static {
        System.loadLibrary("JNITest");
    }
    public native String get();
}


2、在控制台切到上述java类包的根目录下，分别执行：
2.1、javac JNITest.jara // 在java源文件目录下次生成JNITest.class文件
2.2、javah xxx.JNITest // 在根目录下生成一个h文件；


3、采用C或者C++实现上述h文件的接口，即供java调用的接口；
4、把.c、.cpp、.h拷贝到一个名为“jni”目录下；
5、在jni目录下新建Android.mk和Application.mk:

Android.mk:

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := jni-test
LOCAL_SRC_FILES := test.cpp
LOCAL_LDLIBS += -llog
include $(BUILD_SHARED_LIBRARY)


Application.mk：

APP_ABI := all


6、在控制台切到jni目录下，执行
ndk-build

7、在jni同级目录下会生成libs目录，里面就是各个cpu版本的so文件；
