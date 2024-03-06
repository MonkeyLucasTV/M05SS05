package com.example.clientcan;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.clientcan.databinding.ActivityMainBinding;

import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;


import static java.lang.Math.cos;
import static java.lang.Math.sin;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.util.Log;
import android.view.View;


public class MainActivity extends AppCompatActivity {

    // Used to load the 'clientcan' library on application startup.
    static {
        System.loadLibrary("clientcan");
    }



    private ActivityMainBinding binding;
    Button Bouton0B6 = binding.button0B6;
    Button Bouton128 = binding.button128;

    TextView Trame = binding.textViewTrame;
    ImageView feuxCroisement = binding.feuxCroix;
    ImageView feuxRoute = binding.feuxRoute;
    ImageView feuxBrouillard = binding.feuxBrou;
    ImageView ClignoD = binding.clignoD;
    ImageView ClignoG = binding.clignoG;


    String idCANBout = "0B6";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());




        // Example of a call to a native method
        //Trame.setText(stringFromJNI("172.20.21.38","4111",idCANBout));

      /*  ScheduledExecutorService timer = Executors.newSingleThreadScheduledExecutor();
        timer.scheduleAtFixedRate(() -> {



            if(idCANBout == "0B6"){
                Trame.setText(stringFromJNI("172.20.21.38","4111", idCANBout));
                idCANBout = "128";
            }
            else {

                Trame.setText(stringFromJNI("172.20.21.38","4111", idCANBout));
                idCANBout = "0B6";

            }

        }, 0, 5, TimeUnit.SECONDS);*/

        Bouton0B6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String idCANBout = "0B6";
                String Moteur = stringFromJNI("172.20.21.38","4111",idCANBout);
                String Tableaux[]= Moteur.split(" ");

                Trame.setText("Vitesse : "+Tableaux[0]+" km/h \n"+"Regime : "+Tableaux[1]+" rpm");
            }
        });

        Bouton128.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {


                String idCANBout = "128";
                String feux = stringFromJNI("172.20.21.38","4111",idCANBout);
                String Tableau[] = feux.split(" ");

                if(Integer.valueOf(Tableau[1])==1) feuxRoute.setVisibility(View.VISIBLE); else
                    feuxRoute.setVisibility(View.INVISIBLE);
                if(Integer.valueOf(Tableau[2])==1) feuxBrouillard.setVisibility(View.VISIBLE); else
                    feuxBrouillard.setVisibility(View.INVISIBLE);
                if(Integer.valueOf(Tableau[3])==1) ClignoD.setVisibility(View.VISIBLE); else
                    ClignoD.setVisibility(View.INVISIBLE);
                if(Integer.valueOf(Tableau[4])==1) ClignoG.setVisibility(View.VISIBLE); else
                    ClignoG.setVisibility(View.INVISIBLE);
                if(Integer.valueOf(Tableau[0])==1) feuxCroisement.setVisibility(View.VISIBLE); else
                    feuxCroisement.setVisibility(View.INVISIBLE);


                Trame.setText("Feux de croisement : "+Tableau[0]+ " \nFeux de route : "+Tableau[1]+" \nFeux Antibrouillard : " +Tableau[2]+ " \nClignotant Droit : " +Tableau[3]+" \nClignotant Gauche : " +Tableau[4]);
            }
        });

    }






    /**
     * A native method that is implemented by the 'clientcan' native library,
     * which is packaged with this application.
     */

    public native String stringFromJNI(String ip, String port, String idCAN);

}