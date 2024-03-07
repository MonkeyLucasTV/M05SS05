//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#include <iostream>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	ip = AnsiString(InputIp->Text).c_str();
	port = AnsiString(InputPort->Text).c_str();


	short m_port = atoi(port.c_str())

	Timer1->Enabled = true;
	char TrameCAN[50];
	char idCAN[10];



	while(Timer1){



		strcpy(idCAN,"128");
		Client.SeConnecterAUnServeur(ip,m_port);
		Client.Envoyer(idCAN,idCAN.length());
		Client.Recevoir(TrameCAN,50);


		MaComb.EnregistreDonnesCAN(idCAN,TrameCAN);
		if(MaComb.Croisement() == 1) feuxCroix->Visible = true; else feuxCroix->Visible = false;
		if (MaComb.ClingoD() == 1) ClignoD->Visible = true; else ClignoD->Visible = false;
		if (MaComb.ClignoG() ==1) ClignoG->Visible = true; else ClignoG->Visible =false;
		if (MaComb.AntiBrouillardArriere() == 1)    FeuxBrou->Visible = true; FeuxBrou->Visible = false;
		if (MaComb.Route() ==1) feuxRoute->Visible = true; else feuxRoute->Visible = false;


		strcpy(idCAN,"0B6");
		Client.SeConnecterAUnServeur(ip,m_port);
		Client.Envoyer(idCAN.c_str(),idCAN.length());
		Client.Recevoir(TrameCAN,50);


		MaComb.EnregistreDonnesCAN(idCAN, TrameCAN);

	}


}
//---------------------------------------------------------------------------
