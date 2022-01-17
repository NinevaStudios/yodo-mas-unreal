// Copyright (c) 2022 Nineva Studios

#include "YodoAdsBanner.h"

#include "Async/Async.h"

void UYodoAdsBanner::SetSize(EYABannerSize Size)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsBanner::SetSize"));

	if (!IsNativeObjectValid())
		return;

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(UYodoAdsLibrary::YodoAdsClassName, "setBannerSize",
		"(Lcom/yodo1/mas/banner/Yodo1MasBannerAdView;I)V", JavaObject, (int) Size);
#elif PLATFORM_IOS
#endif
}

void UYodoAdsBanner::LoadAd()
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsBanner::LoadAd"));

	if (!IsNativeObjectValid())
		return;

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(UYodoAdsLibrary::YodoAdsClassName, "setBannerCallbacksAndLoad",
		"(Lcom/yodo1/mas/banner/Yodo1MasBannerAdView;J)V", JavaObject, (long) this);
#elif PLATFORM_IOS
#endif
}

void UYodoAdsBanner::Show(EYABannerHorizontalPosition HorizontalPosition, EYABannerVerticalPosition VerticalPosition, const FVector2D& Offset)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsBanner::Show"));

	if (!IsNativeObjectValid())
		return;

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(UYodoAdsLibrary::YodoAdsClassName, "showBannerAd",
		"(Landroid/app/Activity;Lcom/yodo1/mas/banner/Yodo1MasBannerAdView;IIII)V", FJavaWrapper::GameActivityThis, JavaObject, (int) HorizontalPosition, (int) VerticalPosition, Offset.X, Offset.Y);
#elif PLATFORM_IOS
#endif
}

void UYodoAdsBanner::Destroy()
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsBanner::Destroy"));

	if (!IsNativeObjectValid())
		return;

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallVoidMethod(JavaObject, "destroy", "()V");
#elif PLATFORM_IOS
#endif
}

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_ninevastudios_yodoads_YodoAds_OnBannerAdLoaded(JNIEnv* env, jclass clazz, jlong pointer)
{
	UYodoAdsBanner* Banner = reinterpret_cast<UYodoAdsBanner*>(pointer);

	AsyncTask(ENamedThreads::GameThread, [=]() {
		Banner->OnBannerAdLoaded.ExecuteIfBound();
	});
}

JNI_METHOD void Java_com_ninevastudios_yodoads_YodoAds_OnBannerAdFailedToLoad(JNIEnv* env, jclass clazz, jlong pointer, jstring error)
{
	UYodoAdsBanner* Banner = reinterpret_cast<UYodoAdsBanner*>(pointer);

	FString Error = YAJavaConvertor::FromJavaString(error);

	AsyncTask(ENamedThreads::GameThread, [=]() {
		Banner->OnBannerAdFailedToLoad.ExecuteIfBound(Error);
	});
}

JNI_METHOD void Java_com_ninevastudios_yodoads_YodoAds_OnBannerAdOpened(JNIEnv* env, jclass clazz, jlong pointer)
{
	UYodoAdsBanner* Banner = reinterpret_cast<UYodoAdsBanner*>(pointer);

	AsyncTask(ENamedThreads::GameThread, [=]() {
		Banner->OnBannerAdOpened.ExecuteIfBound();
	});
}

JNI_METHOD void Java_com_ninevastudios_yodoads_YodoAds_OnBannerAdFailedToOpen(JNIEnv* env, jclass clazz, jlong pointer, jstring error)
{
	UYodoAdsBanner* Banner = reinterpret_cast<UYodoAdsBanner*>(pointer);

	FString Error = YAJavaConvertor::FromJavaString(error);

	AsyncTask(ENamedThreads::GameThread, [=]() {
		Banner->OnBannerAdFailedToOpen.ExecuteIfBound(Error);
	});
}

JNI_METHOD void Java_com_ninevastudios_yodoads_YodoAds_OnBannerAdClosed(JNIEnv* env, jclass clazz, jlong pointer)
{
	UYodoAdsBanner* Banner = reinterpret_cast<UYodoAdsBanner*>(pointer);

	AsyncTask(ENamedThreads::GameThread, [=]() {
		Banner->OnBannerAdClosed.ExecuteIfBound();
	});
}
#endif