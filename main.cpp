#include <stdio.h>
#include <iostream>
#include "IRClientTCP.h"
#include<windows.h>



unsigned int ChaineHexaVersInt(char* chaineHexa, int nbCar){
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

			if(Repeter != (true || false)) std::cin >> RepRepT;

			if (RepRepT == "Y") {
				Repeter = true;
			}
			else{
				Repeter = false;
			}

			if((strcmp(idCAN, "0B6") == 0) || (strcmp(idCAN, "128") == 0))  break;
		}

		std::cout << "Successfull" << std::endl;
		monclient.SeConnecterAUnServeur("127.0.0.1", 4111);
		monclient.Envoyer(idCAN,strlen(idCAN));
		monclient.Recevoir(trameCAN,50);
		std::cout << trameCAN << std::endl;

		if (Repeter == true) {
				while(true){

					strcpy(idCAN, "0B6");

					monclient.SeConnecterAUnServeur("127.0.0.1", 4111);
					monclient.Envoyer(idCAN,strlen(idCAN));
					monclient.Recevoir(trameCAN,50);
					std::cout << "Trame Moteur : " << trameCAN << std::endl;
					int VitesseEnKmh =  (ChaineHexaVersInt(trameCAN+23, 2)) * 2.55;
					std::cout << "Trame vers hexa : " << ChaineHexaVersInt(trameCAN+23, 2) << std::endl;
					std::cout << "La vitesse : " << VitesseEnKmh << " km/h" << std::endl ;

					int RegimeMoteur = (ChaineHexaVersInt(trameCAN+19,2)) *100 /3.1;
					std::cout << "Le regime moteur : " << RegimeMoteur << " tr/min" << std::endl << std::endl;


					Sleep(500);


					strcpy(idCAN, "128");

					monclient.SeConnecterAUnServeur("127.0.0.1", 4111);
					monclient.Envoyer(idCAN,strlen(idCAN));
					monclient.Recevoir(trameCAN,50);
					std::cout << "Trame Feux : " << trameCAN << std::endl;
					std::cout << "Trame vers hexa : " << ChaineHexaVersInt(trameCAN+23, 2) << std::endl << std::endl << std::endl;
					Sleep(5000);
				}
		}





	}
	return 0;
}
