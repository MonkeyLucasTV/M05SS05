package com.example.clientcan;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.example.clientcan.databinding.ActivityMainBinding;

import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'clientcan' library on application startup.
    static {
        System.loadLibrary("clientcan");
    }



    private ActivityMainBinding binding;

    String idCANBout = "0B6";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        Button Bouton0B6 = binding.button0B6;
        Button Bouton128 = binding.button128;

        // Example of a call to a native method
        TextView Trame = binding.textViewTrame;
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
                Trame.setText(stringFromJNI("172.20.21.38","4111",idCANBout));
            }
        });

        Bouton128.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                String idCANBout = "128";
                String feux = stringFromJNI("172.20.21.38","4111",idCANBout);
                String Tableaux[] = feux.split(" ");

                Trame.setText("Feux de croisement : "+Tableaux[0]+ " \nFeux de route : "+Tableaux[1]+" \nFeux Antibrouillard : " +Tableaux[2]+ " \nClignotant Droit : " +Tableaux[3]+" \nClignotant Gauche : " +Tableaux[4]);
            }
        });

    }






    /**
     * A native method that is implemented by the 'clientcan' native library,
     * which is packaged with this application.
     */

    public native String stringFromJNI(String ip, String port, String idCAN);

}