package com.example.clientcan;

import androidx.appcompat.app.AppCompatActivity;


import android.media.AudioManager;
import android.media.ToneGenerator;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.clientcan.databinding.ActivityMainBinding;
import com.google.android.material.textfield.TextInputEditText;

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

import org.w3c.dom.Text;


public class MainActivity extends AppCompatActivity {

    // Used to load the 'clientcan' library on application startup.
    static {
        System.loadLibrary("clientcan");
    }


    private Button BoutIp ;
    private EditText InputIp;
    private EditText InputPort;
    private String Ip;
    private String Port;
    private Button Bouton0B6;
    private TextView TextLog;
    private TextView TxtRgm;
    private TextView TxtKmh;
    private TextView Trame;
    private ImageView feuxCroisement;
    private ImageView feuxRoute;
    private ImageView feuxBrouillard;
    private ImageView ClignoD;
    private ImageView ClignoG;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        //binding = ActivityMainBinding.inflate(getLayoutInflater());
        //setContentView(binding.getRoot());


       //
        setContentView(R.layout.activity_main);
        CircleView circleView = findViewById(R.id.circleView);
        CircleView circleView2 = findViewById(R.id.circleView2);

        BoutIp = findViewById(R.id.ValidButt);
        InputPort = findViewById(R.id.EditPort);
        InputIp = findViewById(R.id.InputIp);
        TextLog = findViewById(R.id.sample_text);
        Bouton0B6 = findViewById(R.id.button0B6);
        TxtRgm = findViewById(R.id.TextRegime);
        TxtKmh = findViewById(R.id.TextKhm);
        Trame = findViewById(R.id.textView_trame);
        feuxCroisement = findViewById(R.id.feuxCroix);
        feuxBrouillard = findViewById(R.id.feuxBrou);
        feuxRoute = findViewById(R.id.feuxRoute);
        ClignoD = findViewById(R.id.clignoD);
        ClignoG = findViewById(R.id.clignoG);



        Bouton0B6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                ScheduledExecutorService timer = Executors.newSingleThreadScheduledExecutor();
                timer.scheduleAtFixedRate(() -> {







                String idCANBout = "128";
                String feux = stringFromJNI(Ip,"4111",idCANBout);
                String Tableau[] = feux.split(" ");

                    runOnUiThread(() -> {
                                if (Integer.valueOf(Tableau[1]) == 1) feuxRoute.setVisibility(View.VISIBLE);
                                else
                                    feuxRoute.setVisibility(View.INVISIBLE);
                                if (Integer.valueOf(Tableau[2]) == 1)
                                    feuxBrouillard.setVisibility(View.VISIBLE);
                                else
                                    feuxBrouillard.setVisibility(View.INVISIBLE);
                                if (Integer.valueOf(Tableau[3]) == 1) ClignoD.setVisibility(View.VISIBLE);
                                else
                                    ClignoD.setVisibility(View.INVISIBLE);
                                if (Integer.valueOf(Tableau[4]) == 1) ClignoG.setVisibility(View.VISIBLE);
                                else
                                    ClignoG.setVisibility(View.INVISIBLE);
                                if (Integer.valueOf(Tableau[0]) == 1)
                                    feuxCroisement.setVisibility(View.VISIBLE);
                                else
                                    feuxCroisement.setVisibility(View.INVISIBLE);
                            });

                Trame.setText("Feux de croisement : "+Tableau[0]+ " \nFeux de route : "+Tableau[1]+
                        " \nFeux Antibrouillard : " +Tableau[2]+ " \nClignotant Droit : " +Tableau[3]+" \nClignotant Gauche : " +Tableau[4]);


                    try {
                        Thread.sleep(250);
                    } catch (InterruptedException e) {

                    }

                    idCANBout = "0B6";
                String Moteur = stringFromJNI(Ip,"4111",idCANBout);
                String Tableaux[]= Moteur.split(" ");
                TxtKmh.setText(Tableaux[0]+" km/h");
                TxtRgm.setText(Tableaux[1]+" tr/min");
                int VMad = Integer.valueOf(Tableaux[0]);
               // int angle = ;
                circleView.setDrawLine(-((90-220)*VMad/110+220));
                if (Integer.valueOf(Tableaux[0]) >= 130){
                    ToneGenerator toneG = new ToneGenerator(AudioManager.STREAM_ALARM, 0);
                    toneG.startTone(ToneGenerator.TONE_CDMA_INTERCEPT, 150);
                }

                if(Integer.valueOf(Tableaux[0]) >= 130){
                    runOnUiThread(() -> {
                        feuxRoute.setVisibility(View.VISIBLE);
                        feuxBrouillard.setVisibility(View.VISIBLE);
                        ClignoD.setVisibility(View.VISIBLE);
                        ClignoG.setVisibility(View.VISIBLE);
                        feuxCroisement.setVisibility(View.VISIBLE);

                         });

                }


                int RMad = Integer.valueOf(Tableaux[1]);

                circleView2.setDrawLine(-((90-220)*RMad/3000+220));
               // TextLog.setText(String.valueOf(angle));




                    try {
                        Thread.sleep(250);
                    } catch (InterruptedException e) {

                    }
                }, 0, 1, TimeUnit.SECONDS);
            }
        });


        BoutIp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
               Ip = String.valueOf(InputIp.getText());
               Port = String.valueOf(InputPort.getText());
               TextLog.setText(Ip);
            }
        });

    }






    /**
     * A native method that is implemented by the 'clientcan' native library,
     * which is packaged with this application.
     */

    public native String stringFromJNI(String ip, String port, String idCAN);

}