package com.example.ndkpassdata;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends Activity {
	
	private Dataprovider dataprovider;
	
	static{
		System.loadLibrary("hello");
	}

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        dataprovider = new Dataprovider();
    }

    public void add(View v){
    	int reslut = dataprovider.add(2, 5);
    	System.out.println("reslut---" + reslut);
    }
    
    public void addString(View v){
    	String str = dataprovider.sayHelloInC("nihaoa-");
    	Toast.makeText(this, str, 0).show();
    }
    public void testintarray(View v){
    	int [] arr = new int[]{2,3,4,5};
    	dataprovider.intMethod(arr);
    	for (int i = 0; i < arr.length; i++) {
			System.out.println(arr[i]);
		}
    }
}
