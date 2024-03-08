//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "combinec4.h"
#include "IRClientTCP.h"
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Graphics.hpp>
#include <string>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TImage *ClignoG;
	TImage *ClignoD;
	TImage *FeuxBrou;
	TImage *feuxRoute;
	TImage *feuxCroix;
	TImage *Image6;
	TImage *Image7;
	TEdit *InputIp;
	TEdit *InputPort;
	TButton *Button1;
	TLabel *Label1;
	TLabel *Label2;
	TTimer *Timer1;
	TLabel *Kmh;
	TLabel *trmin;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// Déclarations utilisateur
	IRClientTCP Client ;
	CombineC4 MaComb      ;
	std::string ip;
	std::string port;

public:		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
