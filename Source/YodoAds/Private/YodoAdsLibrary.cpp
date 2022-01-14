// Copyright (c) 2022 Nineva Studios

#include "YodoAdsLibrary.h"

#include "YodoAds.h"
#include "YodoAdsLog.h"
#include "YodoAdsBanner.h"

#include "Async/Async.h"

#if PLATFORM_ANDROID
#include "Android/YAMethodCallUtils.h"
#include "Android/YAJavaConvertor.h"
#elif PLATFORM_IOS

#endif

FYAVoidDelegate UYodoAdsLibrary::OnInitializeSuccess;
FYAErrorDelegate UYodoAdsLibrary::OnInitializeError;

const ANSICHAR* UYodoAdsLibrary::YodoAdsClassName = "com/ninevastudios/yodoads/YodoAds";

void UYodoAdsLibrary::SetConfig(const FYodoAdsConfig& Config)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::SetConfig"));

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(YodoAdsClassName, "setConfig",
		"(ZZLjava/lang/String;Ljava/lang/String;)V", Config.EnableUserPrivacyDialog, Config.EnableAdaptiveBanner, 
		YAJavaConvertor::GetJavaString(Config.PrivacyPolicyUrl), YAJavaConvertor::GetJavaString(Config.UserAgreementUrl));
#elif PLATFORM_IOS
#endif
}

void UYodoAdsLibrary::Initialize(const FYAVoidDelegate& OnSuccess, const FYAErrorDelegate& OnError)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::Initialize"));

	OnInitializeSuccess = OnSuccess;
	OnInitializeError = OnError;

	FString AppKey = FYodoAdsModule::Get().GetSettings()->AndroidAppKey;

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(YodoAdsClassName, "initialize",
		"(Landroid/app/Activity;Ljava/lang/String;)V", FJavaWrapper::GameActivityThis, YAJavaConvertor::GetJavaString(AppKey));
#elif PLATFORM_IOS
#endif
}

UYodoAdsBanner* UYodoAdsLibrary::MakeBannerAd()
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::MakeBannerAd"));

	UYodoAdsBanner* Result = NewObject<UYodoAdsBanner>();

#if PLATFORM_ANDROID
	jobject javaBanner = YAMethodCallUtils::CallStaticObjectMethod(YodoAdsClassName, "createBannerView", 
		"(Landroid/app/Activity;)Lcom/yodo1/mas/banner/Yodo1MasBannerAdView;", FJavaWrapper::GameActivityThis);
	Result->Init(javaBanner);
#elif PLATFORM_IOS
#endif

	return Result;
}

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_ninevastudios_yodoads_YodoAds_OnInitSuccess(JNIEnv* env, jclass clazz)
{
	AsyncTask(ENamedThreads::GameThread, [=]() {
		UYodoAdsLibrary::OnInitializeSuccess.ExecuteIfBound();
	});
}

JNI_METHOD void Java_com_ninevastudios_yodoads_YodoAds_OnInitError(JNIEnv* env, jclass clazz, jstring error)
{
	FString Error = YAJavaConvertor::FromJavaString(error);

	AsyncTask(ENamedThreads::GameThread, [=]() {
		UYodoAdsLibrary::OnInitializeError.ExecuteIfBound(Error);
	});
}
#endif