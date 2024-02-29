#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_clientcan_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */,jstring ip, jstring port, jstring idCAN) {
    std::string hello = "Hello from C++";


    std::string m_adresseIPServeur=(const char *)env->GetStringUTFChars(ip, NULL);
    int m_portServeur=atoi(env->GetStringUTFChars(port, NULL));

    return env->NewStringUTF(hello.c_str());



}