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
#include <Vcl.ComCtrls.hpp>
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
	TTrackBar *TrackBar1;
	TTrackBar *TrackBar2;
	TTimer *Timer2;
	TTimer *Timer3;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall TrackBar2Change(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
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
