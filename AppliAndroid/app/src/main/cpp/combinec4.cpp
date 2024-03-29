#include "combinec4.h"
#include "IRClientTCP.h"
#include <iostream>

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


void CombineC4::EnregistreDonnesCAN(char* idCANO, char* trameCANO){



	idCAN = idCANO;
	trameCAN = trameCANO;
	vitesse =  (ChaineHexaVersInt(trameCAN+23, 2)) * 2.55;
	regime = (ChaineHexaVersInt(trameCAN+19,2)) *100 /3.1;

	int EtatFeux = ChaineHexaVersInt(trameCAN+27, 2)  ;

	position = (EtatFeux & (0x01 << 7));
	croisement = (EtatFeux & (0x01 << 6));
	route = (EtatFeux & (0x01 << 5));
	AbAv = (EtatFeux & (0x01 << 4));
	AbAr = (EtatFeux & (0x01 << 3));
	clignoD = (EtatFeux & (0x01 << 2));
	clignoG = (EtatFeux & (0x01 << 1));



}


int CombineC4::Vitesse(){
	return vitesse;
}


int CombineC4::Regime(){

	return regime;
}

int CombineC4::Croisement(){
	return croisement;
}


int CombineC4::AntiBrouillardAvant(){
	return AbAv;
}

int CombineC4::AntiBrouillardArriere(){
	return AbAr;
}

int CombineC4::Route(){
	return route;
}


int CombineC4::ClignoD(){
	return clignoD;
}


int CombineC4::ClignoG(){
	return clignoG;
}


int CombineC4::Position(){
	return position;
}



