#include "IRClientTCP.h"

class CombineC4   {

	private:

	char* trame;
	char* idCAN;
	int vitesse;
	int regime;
	bool croisement;
	bool antiBrouillard;
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
	int AntiBrouillard();
	int Route();
	int ClignD();
	int ClignG();
	int Position();
};
