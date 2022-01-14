// Copyright (c) 2022 Nineva Studios

#include "YAJavaConvertor.h"

namespace YAJavaConvertor
{
TArray<uint8> ToByteArray(jbyteArray JavaArray)
{
	TArray<uint8> ByteArray;

	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jbyte* JavaByte = Env->GetByteArrayElements(JavaArray, 0);

	const int Length = Env->GetArrayLength(JavaArray);
	for (int i = 0; i < Length; i++)
	{
		ByteArray.Add(JavaByte[i]);
	}

	return ByteArray;
}

jbyteArray ToJavaByteArray(const TArray<uint8>& Data)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	const int DataLength = Data.Num();
	jbyteArray LocalArray = Env->NewByteArray(DataLength);

	jbyte Buffer[DataLength];
	for (int i = 0; i < DataLength; i++)
	{
		Buffer[i] = Data[i];
	}

	Env->SetByteArrayRegion(LocalArray, 0, DataLength, Buffer);
	jbyteArray ResultArray = (jbyteArray)Env->NewGlobalRef(LocalArray);
	Env->DeleteLocalRef(LocalArray);

	return ResultArray;
}

jobjectArray ToJavaStringArray(const TArray<FString>& StringArray)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jobjectArray JStringArray = (jobjectArray)Env->NewObjectArray(StringArray.Num(), FJavaWrapper::JavaStringClass, nullptr);

	for (int i = 0; i < StringArray.Num(); i++)
	{
		auto JString = FJavaClassObject::GetJString(StringArray[i]);
		Env->SetObjectArrayElement(JStringArray, i, *JString);
	}

	return JStringArray;
}

FString FromJavaString(jstring javaString)
{
	JNIEnv* Env = AndroidJavaEnv::GetJavaEnv();
	const char* UTFString = Env->GetStringUTFChars(javaString, nullptr);
	FString Result(UTF8_TO_TCHAR(UTFString));
	Env->ReleaseStringUTFChars(javaString, UTFString);
	Env->DeleteLocalRef(javaString);

	return Result;
}

jstring GetJavaString(FString string)
{
	JNIEnv* JEnv = AndroidJavaEnv::GetJavaEnv();
	jstring local = JEnv->NewStringUTF(TCHAR_TO_UTF8(*string));
	jstring result = (jstring)JEnv->NewGlobalRef(local);
	JEnv->DeleteLocalRef(local);
	return result;
}

TArray<FString> ConvertToStringArray(jobjectArray javaStringArray)
{
	TArray<FString> stringArray;

	JNIEnv* Env = FAndroidApplication::GetJavaEnv();

	int length = Env->GetArrayLength(javaStringArray);

	for (int i = 0; i < length; i++)
	{
		jstring javaString = static_cast<jstring>(Env->GetObjectArrayElement(javaStringArray, i));

		stringArray.Add(FromJavaString(javaString));
	}

	return stringArray;
}

}
