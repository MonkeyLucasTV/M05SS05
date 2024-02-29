package com.example.clientcan;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.example.clientcan.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'clientcan' library on application startup.
    static {
        System.loadLibrary("clientcan");
    }

    var idCANBout ="";

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI(127.0.0.1,4111,idCANBout));
    }

    @Override


    /**
     * A native method that is implemented by the 'clientcan' native library,
     * which is packaged with this application.
     */

    public native String stringFromJNI(String ip, String port, String idCAN);

}