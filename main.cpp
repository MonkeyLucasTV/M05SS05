#include <stdio.h>
#include <iostream>
#include "IRClientTCP.h"


 int main()
{

	IRClientTCP monclient;
	char trameCAN[50];
	char idCAN[10];

	while(true){
	while(true){
	std::cout << "Saisissez votre identifiants :  ";
	std::cin >> idCAN ;
	std::cout << "Votre identifiant : " << idCAN << std::endl;

	if((strcmp(idCAN, "0B6") == 0) || (strcmp(idCAN, "128") == 0))  break;
	 }
	std::cout << "Successfull" << std::endl;


	monclient.SeConnecterAUnServeur("172.20.21.26", 4111);
	monclient.Envoyer(idCAN,strlen(idCAN));

	monclient.Recevoir(trameCAN,50);
	std::cout << trameCAN << std::endl;





	}
	return 0;
}
