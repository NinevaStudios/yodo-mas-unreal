// Copyright (c) 2022 Nineva Studios

#include "YodoAdsBanner.h"

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
	YAMethodCallUtils::CallVoidMethod(JavaObject, "loadAd", "()V");
#elif PLATFORM_IOS
#endif
}

void UYodoAdsBanner::Show(EYABannerHorizontalPosition HorizontalPosition, EYABannerVerticalPosition VerticalPosition, const FVector2D& Offset)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsBanner::Show"));

	if (!IsNativeObjectValid())
		return;

	int AlignmentFlags = (int) HorizontalPosition | (int) VerticalPosition;

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(UYodoAdsLibrary::YodoAdsClassName, "showBannerAd",
		"(Landroid/app/Activity;Lcom/yodo1/mas/banner/Yodo1MasBannerAdView;III)V", FJavaWrapper::GameActivityThis, JavaObject, AlignmentFlags, Offset.X, Offset.Y);
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