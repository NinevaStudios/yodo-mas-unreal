// Copyright (c) 2022 Nineva Studios

#include "YodoAdsBanner.h"

#include "Async/Async.h"

#if PLATFORM_IOS
#import <Yodo1MasBannerAdView.h>
#import "IOSAppDelegate.h"

#include "IOS/YAUtils.h"
#include "IOS/YAAdDelegate.h"
YABannerAdDelegate* BannerAdDelegate;
#endif

void UYodoAdsBanner::SetSize(EYABannerSize Size)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsBanner::SetSize"));

	if (!IsNativeObjectValid())
		return;

	BannerSize = Size;

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(UYodoAdsLibrary::YodoAdsClassName, "setBannerSize",
		"(Lcom/yodo1/mas/banner/Yodo1MasBannerAdView;I)V", JavaObject, (int) Size);
#elif PLATFORM_IOS
	[((Yodo1MasBannerAdView*) IOSObject) setAdSize: (Yodo1MasBannerAdSize) Size];
#endif
}

void UYodoAdsBanner::SetPlacement(const FString& PlacementId)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsBanner::SetPlacement"));

	if (!IsNativeObjectValid())
		return;

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallVoidMethod(JavaObject, "setAdPlacement",
		"(Ljava/lang/String;)V", YAJavaConvertor::GetJavaString(PlacementId));
#elif PLATFORM_IOS
	[((Yodo1MasBannerAdView*) IOSObject) setAdPlacement:PlacementId.GetNSString()];
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
	BannerAdDelegate = [YABannerAdDelegate new];
	BannerAdDelegate.onAdOpened = ^() {
		AsyncTask(ENamedThreads::GameThread, [=]() {
			OnBannerAdOpened.ExecuteIfBound();
		});
	};
	BannerAdDelegate.onOpenAdError = ^(Yodo1MasError* error) {
		FString Error = YAUtils::ParseIosError(error);
		
		AsyncTask(ENamedThreads::GameThread, [=]() {
			OnBannerAdFailedToOpen.ExecuteIfBound(Error);
		});
	};
	BannerAdDelegate.onAdLoaded = ^() {
		AsyncTask(ENamedThreads::GameThread, [=]() {
			OnBannerAdLoaded.ExecuteIfBound();
		});
	};
	BannerAdDelegate.onLoadAdError = ^(Yodo1MasError* error) {
		FString Error = YAUtils::ParseIosError(error);
		
		AsyncTask(ENamedThreads::GameThread, [=]() {
			OnBannerAdFailedToLoad.ExecuteIfBound(Error);
		});
	};
	BannerAdDelegate.onAdClosed = ^() {
		AsyncTask(ENamedThreads::GameThread, [=]() {
			OnBannerAdClosed.ExecuteIfBound();
		});
	};
	
	((Yodo1MasBannerAdView*) IOSObject).adDelegate = BannerAdDelegate;
	
	dispatch_async(dispatch_get_main_queue(), ^{
		[((Yodo1MasBannerAdView*) IOSObject) loadAd];
	});
#endif
}

#if PLATFORM_IOS
int calculatePositionX(EYABannerHorizontalPosition alignmentHorizontal, int screenWidth, int bannerWidth, int offsetX, EYABannerSize size) {
	int position;
	if (alignmentHorizontal == EYABannerHorizontalPosition::Left || size == EYABannerSize::AdaptiveBanner) {
		position = 0;
	} else if (alignmentHorizontal == EYABannerHorizontalPosition::Right) {
		position = screenWidth - bannerWidth;
	} else {
		position = (screenWidth - bannerWidth) / 2;
	}

	return position + offsetX;
}

int calculatePositionY(EYABannerVerticalPosition alignmentVertical, int screenHeight, int bannerHeight, int offsetY) {
	int position;
	if (alignmentVertical == EYABannerVerticalPosition::Top) {
		position = 0;
	} else if (alignmentVertical == EYABannerVerticalPosition::Bottom) {
		position = screenHeight - bannerHeight;
	} else {
		position = (screenHeight - bannerHeight) / 2;
	}

	return position + offsetY;
}

void setBannerPosition(UIView* gameView, Yodo1MasBannerAdView* banner, EYABannerHorizontalPosition alignmentHorizontal, EYABannerVerticalPosition alignmentVertical, int offsetX, int offsetY, EYABannerSize bannerSize) {
	CGSize screenSize = gameView.bounds.size;
	
	int screenWidth = screenSize.width;
	int screenHeight = screenSize.height;
	
	CGSize size = banner.intrinsicContentSize;

	int bannerWidth = size.width;
	int bannerHeight = size.height;

	int positionX = calculatePositionX(alignmentHorizontal, screenWidth, bannerWidth, offsetX, bannerSize);
	int positionY = calculatePositionY(alignmentVertical, screenHeight, bannerHeight, offsetY);
	
	banner.frame = CGRectMake(positionX, positionY, bannerWidth, bannerHeight);
}
#endif

void UYodoAdsBanner::Show(EYABannerHorizontalPosition HorizontalPosition, EYABannerVerticalPosition VerticalPosition, const FVector2D& Offset)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsBanner::Show"));

	if (!IsNativeObjectValid())
		return;

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(UYodoAdsLibrary::YodoAdsClassName, "showBannerAd",
		"(Landroid/app/Activity;Lcom/yodo1/mas/banner/Yodo1MasBannerAdView;IIIII)V", FJavaWrapper::GameActivityThis, JavaObject, 
		(int) BannerSize, (int) HorizontalPosition, (int) VerticalPosition, (int) Offset.X, (int) Offset.Y);
#elif PLATFORM_IOS
	Yodo1MasBannerAdView* banner = (Yodo1MasBannerAdView*) IOSObject;
	
	UIView* gameView = [IOSAppDelegate GetDelegate].IOSController.view;
	
	setBannerPosition(gameView, banner, HorizontalPosition, VerticalPosition, (int) Offset.X, (int) Offset.Y, BannerSize);
	
	dispatch_async(dispatch_get_main_queue(), ^{
		[gameView addSubview:banner];
	});
#endif
}

void UYodoAdsBanner::Destroy()
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsBanner::Destroy"));

	if (!IsNativeObjectValid())
		return;

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(UYodoAdsLibrary::YodoAdsClassName, "destroyBannerAd",
		"(Landroid/app/Activity;Lcom/yodo1/mas/banner/Yodo1MasBannerAdView;)V", FJavaWrapper::GameActivityThis, JavaObject);
#elif PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		[((Yodo1MasBannerAdView*) IOSObject) destroy];
	});
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
