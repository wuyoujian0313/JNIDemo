package wuyj.com.jnidemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        JNITest jniTest = new JNITest();
        Log.d("JNIDemo",jniTest.get()+":"+jniTest.Add(10,10));

        jniTest.callPrintStaticStr();

        TextView textView = (TextView)findViewById(R.id.textView);
        textView.setText(jniTest.get());
    }
}
