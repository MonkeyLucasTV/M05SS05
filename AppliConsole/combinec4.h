#include "IRClientTCP.h"

class CombineC4   {

	private:

	char* trameCAN;
	char* idCAN;
	int vitesse;
	int regime;
	bool croisement;
	bool AbAv;
	bool AbAr;
	bool route;
	bool clignoD;
	bool position;
	bool clignoG;
	IRClientTCP monclient;

	public:

	CombineC4();
	~CombineC4();
	unsigned int ChaineHexaVersInt(char* chaineHexa, int nbCar);
	void EnregistreDonnesCAN(char* idCAN, char* trameCAN);
	int Vitesse();
	int Regime();
	int Croisement();
	int AntiBrouillardAvant();
	int AntiBrouillardArriere();
	int Route();
	int ClingoD();
	int ClignoG();
	int Position();
};