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

int x1,y1,x2,y2;



void Aiguille(TImage * Image, TTrackBar * Tb,int &x,int &y){
	Image->Picture->Bitmap->Canvas->MoveTo(250,250);
	Image->Picture->Bitmap->Canvas->Pen->Color = 0xFFFFFF;
	Image->Picture->Bitmap->Canvas->LineTo(250+x,250+y);
	Image->Picture->Bitmap->Canvas->Pen->Color = 0x00FF00;
	Image->Picture->Bitmap->Canvas->MoveTo(250,250);
	int alpha = Tb->Position;
	x = 235*cos((alpha*M_PI)/180);
	y = 235*sin((alpha*M_PI)/180);
	Image->Picture->Bitmap->Canvas->LineTo(250+x,250+y);
}


void AiguilleR(TImage * Image, int Tb,int &x,int &y){
	Image->Picture->Bitmap->Canvas->MoveTo(250,250);
	Image->Picture->Bitmap->Canvas->Pen->Color = 0xFFFFFF;
	Image->Picture->Bitmap->Canvas->LineTo(250+x,250+y);
	Image->Picture->Bitmap->Canvas->Pen->Color = 0x00FF00;
	Image->Picture->Bitmap->Canvas->MoveTo(250,250);
	int alpha = Tb;
	x = 235*cos((alpha*M_PI)/180);
	y = 235*sin((alpha*M_PI)/180);
	Image->Picture->Bitmap->Canvas->LineTo(250+x,250+y);
}

void Cadran(TImage * img){
	img->Picture->Bitmap->Canvas->Pen->Width = 3;
	img->Picture->Bitmap->Canvas->Pen->Color = 0x00FF00;
	img->Picture->Bitmap->Canvas->Ellipse(10,10,490,490);
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

	Cadran(Image6);
	Cadran(Image7);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	ip = AnsiString(InputIp->Text).c_str();
	port = AnsiString(InputPort->Text).c_str();
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{

	char TrameCAN[50];
	char idCAN[10];
	short m_port = atoi(port.c_str());

		strcpy(idCAN,"128");
		Client.SeConnecterAUnServeur(ip,m_port);
		Client.Envoyer(idCAN,strlen(idCAN));
		Client.Recevoir(TrameCAN,50);


		MaComb.EnregistreDonnesCAN(idCAN,TrameCAN);
		if(MaComb.Croisement() == 1) feuxCroix->Visible = true; else feuxCroix->Visible = false;
		if (MaComb.ClingoD() == 1) ClignoD->Visible = true; else ClignoD->Visible = false;
		if (MaComb.ClignoG() ==1) ClignoG->Visible = true; else ClignoG->Visible =false;
		if ((MaComb.AntiBrouillardArriere() == 1) || (MaComb.AntiBrouillardAvant() == 1)) FeuxBrou->Visible = true; else FeuxBrou->Visible = false;
		if (MaComb.Route() ==1) feuxRoute->Visible = true; else feuxRoute->Visible = false;


		strcpy(idCAN,"0B6");
		Client.SeConnecterAUnServeur(ip,m_port);
		Client.Envoyer(idCAN,strlen(idCAN));
		Client.Recevoir(TrameCAN,50);
		MaComb.EnregistreDonnesCAN(idCAN, TrameCAN);
		Kmh->Caption = (String) MaComb.Vitesse() + " km/h";
		trmin->Caption = (String)MaComb.Regime() + " trmin";



		int AngleMot = (-((90-220)*MaComb.Vitesse()/110+220));
		int AngleReg = (-((90-220)*MaComb.Regime()/3000+220));

		AiguilleR(Image6,AngleMot,x1,y1);
		AiguilleR(Image7,AngleReg,x2,y2);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{

	  Timer3->Enabled = true;
	}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar2Change(TObject *Sender)
{
	
	  Timer2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
	  Aiguille(Image7,TrackBar2,x2,y2);
	  Timer2->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
	Aiguille(Image6,TrackBar1,x2,y2);
	Timer3->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

