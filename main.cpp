#include <stdio.h>
#include <iostream>
#include "IRClientTCP.h"
#include<windows.h>



unsigned int ChaineHexaVersInt(char* chaineHexa, int nbCar){
	int nombre,j = 0;
	char caractere;
	for( j=0 ; j<nbCar ; j++ ){
		caractere = chaineHexa[j];
		if (caractere >='0' && caractere <= '9') {
			nombre = nombre + ((caractere -'0')<<(4*(nbCar-j-1)));
		}
		else nombre = nombre + ((caractere - 'A'+10)<<(4*nbCar-j-1));
	}
	return nombre;
}

 int main()
{

	IRClientTCP monclient;
	char trameCAN[50];
	char idCAN[10];
	std::string RepRepT;
	bool Repeter;

	while(true){
		while(true){
			std::cout << "Saisissez votre identifiants :  ";
			std::cin >> idCAN ;
			std::cout << "Votre identifiant : " << idCAN << std::endl;
			std::cout << "Repeter les 2 en boucle ? (Y/N) : ";
			std::cin >> RepRepT;
			if (RepRepT == "Y") {
				Repeter = true;
			}
			else{
				Repeter = false;
			}

			if((strcmp(idCAN, "0B6") == 0) || (strcmp(idCAN, "128") == 0))  break;
		}

		std::cout << "Successfull" << std::endl;
		monclient.SeConnecterAUnServeur("172.20.21.26", 4111);
		monclient.Envoyer(idCAN,strlen(idCAN));
		monclient.Recevoir(trameCAN,50);
		std::cout << trameCAN << std::endl;

		if (Repeter == true) {
				while(true){
					strcpy(idCAN, "0B6");

					monclient.SeConnecterAUnServeur("172.20.21.26", 4111);
					monclient.Envoyer(idCAN,strlen(idCAN));
					monclient.Recevoir(trameCAN,50);
					std::cout << "Trame Moteur : " << trameCAN << std::endl;
					Sleep(1200);

					strcpy(idCAN, "128");

					monclient.SeConnecterAUnServeur("172.20.21.26", 4111);
					monclient.Envoyer(idCAN,strlen(idCAN));
					monclient.Recevoir(trameCAN,50);
					std::cout << "Trame Feux : " << trameCAN << std::endl;
					Sleep(2000);
				}
		}





	}
	return 0;
}
