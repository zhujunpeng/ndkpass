package com.example.ndkpassdata;

public class Dataprovider {

	/**
	 * 计算x和y的加法，在数据进行加密的过程中，不易被反编译
	 * @param x
	 * @param y
	 * @return
	 */
	public native int add(int x , int y);
	/**
	 * 给字符串后面拼装字符，常用于加密运算，web url加密
	 * @param s
	 * @return
	 */
	public native String sayHelloInC(String s);
	/**
	 * 给C代码传递int数组 让C代码给这个数组进行操作
	 * 图形，声音处理
	 * @param iNum
	 * @return
	 */
	public native int[] intMethod(int[] iNum);
}
