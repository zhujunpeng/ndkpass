package com.example.ndkpassdata;

public class Dataprovider {

	/**
	 * ����x��y�ļӷ��������ݽ��м��ܵĹ����У����ױ�������
	 * @param x
	 * @param y
	 * @return
	 */
	public native int add(int x , int y);
	/**
	 * ���ַ�������ƴװ�ַ��������ڼ������㣬web url����
	 * @param s
	 * @return
	 */
	public native String sayHelloInC(String s);
	/**
	 * ��C���봫��int���� ��C��������������в���
	 * ͼ�Σ���������
	 * @param iNum
	 * @return
	 */
	public native int[] intMethod(int[] iNum);
}