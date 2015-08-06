#include <stdio.h>
#include "com_example_ndkpassdata_Dataprovider.h"
#include <android/log.h>
#include <String.h>
// ��C��ʹ��logcat
#define LOG_TAG "System.out.c"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)


// Java String ����ת����C string����
char*   Jstring2CStr(JNIEnv*   env,   jstring   jstr)
{
	 char*   rtn   =   NULL;
	 jclass   clsstring   =   (*env)->FindClass(env,"java/lang/String");
	 jstring   strencode   =   (*env)->NewStringUTF(env,"GB2312");
	 jmethodID   mid   =   (*env)->GetMethodID(env,clsstring,   "getBytes",   "(Ljava/lang/String;)[B");
	 jbyteArray   barr=   (jbyteArray)(*env)->CallObjectMethod(env,jstr,mid,strencode); // String .getByte("GB2312");
	 jsize   alen   =   (*env)->GetArrayLength(env,barr);
	 jbyte*   ba   =   (*env)->GetByteArrayElements(env,barr,JNI_FALSE);
	 if(alen   >   0)
	 {
	  rtn   =   (char*)malloc(alen+1);         //"\0"
	  memcpy(rtn,ba,alen);
	  rtn[alen]=0;
	 }
	 (*env)->ReleaseByteArrayElements(env,barr,ba,0);  //
	 return rtn;
}
jint JNICALL Java_com_example_ndkpassdata_Dataprovider_add
  (JNIEnv * env, jobject obj, jint x, jint y){
	// ��ӡlogcat
	LOGD("x = %d",x);
	LOGI("y = %d",y);

	return x+y;
}

JNIEXPORT jstring JNICALL Java_com_example_ndkpassdata_Dataprovider_sayHelloInC
  (JNIEnv * env, jobject obj, jstring str){

	char * c = "hello";
	// ��c�����в���ֱ�Ӳ���java�е��ַ���
	// Java String ����ת����C string����
	char* cstr = Jstring2CStr(env,str);
	// ƴ��
	strcat(cstr,c);
	LOGI("cstr = %s",cstr);
	return (*env)->NewStringUTF(env,cstr);
}
JNIEXPORT jintArray JNICALL Java_com_example_ndkpassdata_Dataprovider_intMethod
  (JNIEnv * env, jobject jobject, jintArray jarray){
	// jarray �������� jint*       (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
	// ��ȡ���鳤��   jsize       (*GetArrayLength)(JNIEnv*, jarray);
	// �������е�ÿ��Ԫ�� +5
	int lengh = (*env)->GetArrayLength(env,jarray);
	int* arrary = (*env)->GetIntArrayElements(env,jarray,0);
	int i = 0;
	for (i; i < lengh; ++i) {
		arrary[i] += 5;
	}
	return jarray;
}