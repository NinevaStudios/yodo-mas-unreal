// Copyright (c) 2022 Nineva Studios

#pragma once

#include "UObject/Object.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#endif

#include "NativeObjectWrapper.generated.h"

UCLASS(BlueprintType)
class UNativeObjectWrapper : public UObject
{
	GENERATED_BODY()

public:

	virtual ~UNativeObjectWrapper();

	/**
	 * Convenience function to check whether the native object is valid.
	 */
	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	bool IsNativeObjectValid();

#if PLATFORM_ANDROID
	void Init(jobject javaObject);
	jobject JavaObject;
#endif

#if PLATFORM_IOS
	void Init(id iOSObject);
	id IOSObject;
#endif

};