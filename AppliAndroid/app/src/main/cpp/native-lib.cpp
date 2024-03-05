#include <jni.h>
#include <string>
#include <syslog.h>
#include <string.h>
#include "IRClientTCP.h"
#include <stdio.h>
#include <iostream>


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_clientcan_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */, jstring ip,jstring port, jstring idCAN) {
    std::string hello = "Hello from C++";



    std::string m_adresseIPServeur=(const char *)env->GetStringUTFChars(ip, NULL);
    std::string IDCAN=(const char *)env->GetStringUTFChars(idCAN, NULL);
    short m_portServeur=atoi(env->GetStringUTFChars(port, NULL));


    syslog(LOG_INFO, "hello world");



    char trameCAN[50];



    IRClientTCP Client;
    Client.SeConnecterAUnServeur(m_adresseIPServeur, m_portServeur);
    Client.Envoyer(IDCAN.c_str(),IDCAN.length());
    Client.Recevoir(trameCAN, 50);


    return env->NewStringUTF(trameCAN);


}