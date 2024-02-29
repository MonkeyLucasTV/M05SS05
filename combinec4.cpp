#include "combinec4.h"
#include "IRClientTCP.h"

CombineC4::CombineC4(){
}

CombineC4::~CombineC4(){
}

unsigned int CombineC4::ChaineHexaVersInt(char* chaineHexa, int nbCar){
	int nombre=0,j = 0;
	char caractere;
	for( j=0 ; j<nbCar ; j++ ){
		caractere = chaineHexa[j];
		//std::cout << "Le caractere : " << caractere << std::endl;
		if(caractere >='0' && caractere <= '9'){
			nombre = nombre + ((caractere -'0')<<(4*(nbCar-j-1)));
			//std::cout << "Le nombre : " << nombre << std::endl;
		}
		else{
			nombre = nombre + ((caractere - 'A'+10)<<(4*(nbCar-j-1)));
			//std::cout << "Le nombre : " << nombre << std::endl;
		}
	}
	return nombre;
}


void CombineC4::EnregistreDonnesCAN(char* idCAN, char* trameCAN){


	idCAN = idCAN;
	trameCAN = trameCAN;

	vitesse =  (ChaineHexaVersInt(trameCAN+23, 2)) * 2.55;
    regime = (ChaineHexaVersInt(trameCAN+19,2)) *100 /3.1;



	strcpy(idCAN, "128");
	monclient.SeConnecterAUnServeur("127.0.0.1", 4111);
	monclient.Envoyer(idCAN,strlen(idCAN));
	monclient.Recevoir(trameCAN,50);
	int EtatFeux = ChaineHexaVersInt(trameCAN+27, 2)  ;

	 position = EtatFeux & (0x01 << 7);
	 Croisement = EtatFeux & (0x01 << 6);
	 Route = EtatFeux & (0x01 << 5);
	 AbAv = EtatFeux & (0x01 << 4);
	 AbAr = EtatFeux & (0x01 << 3);
	 ClignD = EtatFeux & (0x01 << 2);
	 ClignG = EtatFeux & (0x01 << 1);
}

int CombineC4::Vitesse(){
	return vitesse;
}

int CombineC4::Croisement(){
	return croisement;
}

int CombineC4::AntiBrouillard(){
	return antiBrouillard;
}

int CombineC4::Route(){
	return route;
}

int CombineC4::ClingoD(){
	return clignoD
}

int CombineC4::ClignoG(){
	return clignoG;
}

int CombineC4::Position(){
	return postion;
}


