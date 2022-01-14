// Copyright (c) 2022 Nineva Studios

#include "NativeObjectWrapper.h"

#include "YodoAdsLog.h"

#if PLATFORM_ANDROID
#include "Android/YAMethodCallUtils.h"
#include "Android/YAJavaConvertor.h"
#endif

UNativeObjectWrapper::~UNativeObjectWrapper()
{
	if (!IsNativeObjectValid())
	{
		return;
	}

#if PLATFORM_ANDROID
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	Env->DeleteGlobalRef(JavaObject);
	JavaObject = nullptr;
#elif PLATFORM_IOS
	[IOSObject release];
#endif
}

bool UNativeObjectWrapper::IsNativeObjectValid()
{
	bool Result = false;

#if PLATFORM_ANDROID
	Result = JavaObject != nullptr;
#elif PLATFORM_IOS
	Result = IOSObject != nil;
#endif

#if !WITH_EDITOR
	if (!Result)
	{
		UE_LOG(LogYodoAds, Error, TEXT("Native object is not valid."));
	}
#endif

	return Result;
}

#if PLATFORM_ANDROID
void UNativeObjectWrapper::Init(jobject javaObject)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	JavaObject = Env->NewGlobalRef(javaObject);
}
#endif

#if PLATFORM_IOS
void UNativeObjectWrapper::Init(id iOSObject)
{
	if (iOSObject == nil) {
		return;
	}
	IOSObject = iOSObject;
	[IOSObject retain] ;
}
#endif