#include <jni.h>
#include <string>
#include <syslog.h>
#include "combinec4.h"
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
    CombineC4 komb;

    Client.SeConnecterAUnServeur(m_adresseIPServeur, m_portServeur);
    Client.Envoyer(IDCAN.c_str(),IDCAN.length());
    Client.Recevoir(trameCAN, 50);


    komb.EnregistreDonnesCAN(const_cast<char *>(IDCAN.c_str()), trameCAN);
    char donnees[500];
    if(IDCAN=="0B6")
    { sprintf(donnees,"%d %d",komb.Vitesse(),komb.Regime());
    }
    else
    { sprintf(donnees,"%d %d %d %d %d",
              komb.Croisement(),komb.Route(),komb.AntiBrouillardArriere(),
              komb.ClignoD(),komb.ClignoG());
    }

    return env->NewStringUTF(donnees);


}