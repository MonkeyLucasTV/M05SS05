#ifndef IRCLIENTTCP_H
#define IRCLIENTTCP_H
#include <string>
#define WIN32_LEAN_AND_MEAN
using namespace std;

class IRClientTCP
{

public:
    IRClientTCP();
    bool SeConnecterAUnServeur(string adresseIPServeur, unsigned short portServeur);
    bool SeDeconnecter();
    bool Envoyer(const char * requete,int longueur);
    int Recevoir(char * reponse, int tailleMax);



private :
    static int nbClientTCP;
    int m_maSocket;
    string m_adresseIPServeur;
    unsigned short m_portServeur;

};

#endif // CLIENTHTTP_H
