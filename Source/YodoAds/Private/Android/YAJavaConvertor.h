// Copyright (c) 2022 Nineva Studios

#pragma once

#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidJava.h"

namespace YAJavaConvertor
{
TArray<uint8> ToByteArray(jbyteArray JavaArray);
jbyteArray ToJavaByteArray(const TArray<uint8>& Data);
jobjectArray ToJavaStringArray(const TArray<FString>& StringArray);
FString FromJavaString(jstring javaString);
jstring GetJavaString(FString string);
TArray<FString> ConvertToStringArray(jobjectArray javaStringArray);
};
