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
#import <Yodo1Mas.h>
#include "IOS/YAAdDelegate.h"
#include "IOS/YAUtils.h"
static YAInterstitialAdDelegate* InterstitialAdDelegate;
static YARewardedAdDelegate* RewardedAdDelegate;
#endif

FYAVoidDelegate UYodoAdsLibrary::OnInitializeSuccess;
FYAErrorDelegate UYodoAdsLibrary::OnInitializeError;

FYAVoidDelegate UYodoAdsLibrary::OnRewardedAdOpened;
FYAErrorDelegate UYodoAdsLibrary::OnRewardedAdError;
FYAVoidDelegate UYodoAdsLibrary::OnRewardedAdClosed;
FYAVoidDelegate UYodoAdsLibrary::OnRewardedAdRewardEarned;

FYAVoidDelegate UYodoAdsLibrary::OnInterstitialAdOpened;
FYAErrorDelegate UYodoAdsLibrary::OnInterstitialAdError;
FYAVoidDelegate UYodoAdsLibrary::OnInterstitialAdClosed;

const ANSICHAR* UYodoAdsLibrary::YodoAdsClassName = "com/ninevastudios/yodoads/YodoAds";

void UYodoAdsLibrary::SetConfig(const FYodoAdsConfig& Config)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::SetConfig"));

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(YodoAdsClassName, "setConfig",
		"(ZZLjava/lang/String;Ljava/lang/String;)V", Config.EnableUserPrivacyDialog, Config.EnableAdaptiveBanner, 
		YAJavaConvertor::GetJavaString(Config.PrivacyPolicyUrl), YAJavaConvertor::GetJavaString(Config.UserAgreementUrl));
#elif PLATFORM_IOS
	Yodo1MasAdBuildConfig *config = [Yodo1MasAdBuildConfig instance];
	
	config.enableUserPrivacyDialog = Config.EnableUserPrivacyDialog;
	config.enableAdaptiveBanner = Config.EnableAdaptiveBanner;
	config.privacyPolicyUrl = Config.PrivacyPolicyUrl.GetNSString();
	config.userAgreementUrl = Config.UserAgreementUrl.GetNSString();
	
	[[Yodo1Mas sharedInstance] setAdBuildConfig:config];
#endif
}

void UYodoAdsLibrary::Initialize(const FYAVoidDelegate& OnSuccess, const FYAErrorDelegate& OnError)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::Initialize"));

	OnInitializeSuccess = OnSuccess;
	OnInitializeError = OnError;

#if PLATFORM_ANDROID
	FString AppKey = FYodoAdsModule::Get().GetSettings()->AndroidAppKey;
	
	YAMethodCallUtils::CallStaticVoidMethod(YodoAdsClassName, "initialize",
		"(Landroid/app/Activity;Ljava/lang/String;)V", FJavaWrapper::GameActivityThis, YAJavaConvertor::GetJavaString(AppKey));
#elif PLATFORM_IOS
	FString AppKey = FYodoAdsModule::Get().GetSettings()->iOSAppKey;
	
	[[Yodo1Mas sharedInstance] initWithAppKey:AppKey.GetNSString() successful:^() {
		AsyncTask(ENamedThreads::GameThread, [=]() {
			UYodoAdsLibrary::OnInitializeSuccess.ExecuteIfBound();
		});
	} fail:^(Yodo1MasError* error) {
		FString Error = YAUtils::ParseIosError(error);
		
		AsyncTask(ENamedThreads::GameThread, [=]() {
			UYodoAdsLibrary::OnInitializeError.ExecuteIfBound(Error);
		});
	}];
#endif
}

void UYodoAdsLibrary::SetGDPR(bool UserConsent)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::SetGDPR"));

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(YodoAdsClassName, "setGDPR", "(Z)V", UserConsent);
#elif PLATFORM_IOS
	[Yodo1Mas sharedInstance].isGDPRUserConsent = UserConsent;
#endif
}

bool UYodoAdsLibrary::IsGDPRUserConsent()
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::IsGDPRUserConsent"));

	bool Result = false;

#if PLATFORM_ANDROID
	Result = YAMethodCallUtils::CallStaticBoolMethod(YodoAdsClassName, "isGDPRUserConsent", "()Z");
#elif PLATFORM_IOS
	Result = [Yodo1Mas sharedInstance].isGDPRUserConsent;
#endif

	return Result;
}

void UYodoAdsLibrary::SetCOPPA(bool AgeRestricted)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::SetCOPPA"));

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(YodoAdsClassName, "setCOPPA", "(Z)V", AgeRestricted);
#elif PLATFORM_IOS
	[Yodo1Mas sharedInstance].isCOPPAAgeRestricted = AgeRestricted;
#endif
}

bool UYodoAdsLibrary::IsCOPPAAgeRestricted()
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::IsCOPPAAgeRestricted"));

	bool Result = false;

#if PLATFORM_ANDROID
	Result = YAMethodCallUtils::CallStaticBoolMethod(YodoAdsClassName, "isCOPPAAgeRestricted", "()Z");
#elif PLATFORM_IOS
	Result = [Yodo1Mas sharedInstance].isCOPPAAgeRestricted;
#endif

	return Result;
}

void UYodoAdsLibrary::SetCCPA(bool DontSell)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::SetCCPA"));

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(YodoAdsClassName, "setCCPA", "(Z)V", DontSell);
#elif PLATFORM_IOS
	[Yodo1Mas sharedInstance].isCCPADoNotSell = DontSell;
#endif
}

bool UYodoAdsLibrary::IsCCPADontSell()
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::IsCCPADoNotSell"));

	bool Result = false;

#if PLATFORM_ANDROID
	Result = YAMethodCallUtils::CallStaticBoolMethod(YodoAdsClassName, "isCCPADoNotSell", "()Z");
#elif PLATFORM_IOS
	Result = [Yodo1Mas sharedInstance].isCCPADoNotSell;
#endif

	return Result;
}

void UYodoAdsLibrary::SetRewardedAdListener(const FYAVoidDelegate& OnOpened, const FYAErrorDelegate& OnError, const FYAVoidDelegate& OnClosed, const FYAVoidDelegate& OnRewardEarned)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::SetRewardedAdListener"));

	OnRewardedAdOpened = OnOpened;
	OnRewardedAdError = OnError;
	OnRewardedAdClosed = OnClosed;
	OnRewardedAdRewardEarned = OnRewardEarned;

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(YodoAdsClassName, "setRewardListener", "()V");
#elif PLATFORM_IOS
	RewardedAdDelegate = [YARewardedAdDelegate new];
	RewardedAdDelegate.onAdOpened = ^() {
		AsyncTask(ENamedThreads::GameThread, [=]() {
			OnRewardedAdOpened.ExecuteIfBound();
		});
	};
	RewardedAdDelegate.onAdError = ^(Yodo1MasError* error) {
		FString Error = YAUtils::ParseIosError(error);
		
		AsyncTask(ENamedThreads::GameThread, [=]() {
			OnRewardedAdError.ExecuteIfBound(Error);
		});
	};
	RewardedAdDelegate.onAdClosed = ^() {
		AsyncTask(ENamedThreads::GameThread, [=]() {
			OnRewardedAdClosed.ExecuteIfBound();
		});
	};
	RewardedAdDelegate.onReward = ^() {
		AsyncTask(ENamedThreads::GameThread, [=]() {
			OnRewardedAdRewardEarned.ExecuteIfBound();
		});
	};
	
	[Yodo1Mas sharedInstance].rewardAdDelegate = RewardedAdDelegate;
#endif
}

bool UYodoAdsLibrary::IsRewardedAdLoaded()
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::IsRewardedAdLoaded"));

	bool Result = false;

#if PLATFORM_ANDROID
	Result = YAMethodCallUtils::CallStaticBoolMethod(YodoAdsClassName, "isRewardedAdLoaded", "()Z");
#elif PLATFORM_IOS
	Result = [[Yodo1Mas sharedInstance] isRewardAdLoaded];
#endif

	return Result;
}

void UYodoAdsLibrary::ShowRewardedAd(const FString& Placement)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::ShowRewardedAd"));

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(YodoAdsClassName, "showRewardedAd", "(Landroid/app/Activity;Ljava/lang/String;)V", FJavaWrapper::GameActivityThis, YAJavaConvertor::GetJavaString(Placement));
#elif PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		[[Yodo1Mas sharedInstance] showRewardAd];
	});
#endif
}

void UYodoAdsLibrary::SetInterstitialAdListener(const FYAVoidDelegate& OnOpened, const FYAErrorDelegate& OnError, const FYAVoidDelegate& OnClosed)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::SetInterstitialAdListener"));

	OnInterstitialAdOpened = OnOpened;
	OnInterstitialAdError = OnError;
	OnInterstitialAdClosed = OnClosed;

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(YodoAdsClassName, "setInterstitialListener", "()V");
#elif PLATFORM_IOS
	InterstitialAdDelegate = [YAInterstitialAdDelegate new];
	InterstitialAdDelegate.onAdOpened = ^() {
		AsyncTask(ENamedThreads::GameThread, [=]() {
			OnInterstitialAdOpened.ExecuteIfBound();
		});
	};
	RewardedAdDelegate.onAdError = ^(Yodo1MasError* error) {
		FString Error = YAUtils::ParseIosError(error);
		
		AsyncTask(ENamedThreads::GameThread, [=]() {
			OnInterstitialAdError.ExecuteIfBound(Error);
		});
	};
	InterstitialAdDelegate.onAdClosed = ^() {
		AsyncTask(ENamedThreads::GameThread, [=]() {
			OnInterstitialAdClosed.ExecuteIfBound();
		});
	};
	
	[Yodo1Mas sharedInstance].interstitialAdDelegate = InterstitialAdDelegate;
#endif
}

bool UYodoAdsLibrary::IsInterstitialAdLoaded()
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::IsInterstitialAdLoaded"));

	bool Result = false;

#if PLATFORM_ANDROID
	Result = YAMethodCallUtils::CallStaticBoolMethod(YodoAdsClassName, "isInterstitialAdLoaded", "()Z");
#elif PLATFORM_IOS
	Result = [[Yodo1Mas sharedInstance] isInterstitialAdLoaded];
#endif

	return Result;
}

void UYodoAdsLibrary::ShowInterstitialAd(const FString& Placement)
{
	UE_LOG(LogYodoAds, Verbose, TEXT("UYodoAdsLibrary::ShowInterstitialAd"));

#if PLATFORM_ANDROID
	YAMethodCallUtils::CallStaticVoidMethod(YodoAdsClassName, "showInterstitialAd", "(Landroid/app/Activity;Ljava/lang/String;)V", FJavaWrapper::GameActivityThis, YAJavaConvertor::GetJavaString(Placement));
#elif PLATFORM_IOS
	dispatch_async(dispatch_get_main_queue(), ^{
		[[Yodo1Mas sharedInstance] showInterstitialAd];
	});
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
	Yodo1MasBannerAdView* Banner = [[Yodo1MasBannerAdView alloc] init];
	Result->Init(Banner);
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

JNI_METHOD void Java_com_ninevastudios_yodoads_YodoAds_OnRewardedAdOpened(JNIEnv* env, jclass clazz)
{
	AsyncTask(ENamedThreads::GameThread, [=]() {
		UYodoAdsLibrary::OnRewardedAdOpened.ExecuteIfBound();
	});
}

JNI_METHOD void Java_com_ninevastudios_yodoads_YodoAds_OnRewardedAdError(JNIEnv* env, jclass clazz, jstring error)
{
	FString Error = YAJavaConvertor::FromJavaString(error);

	AsyncTask(ENamedThreads::GameThread, [=]() {
		UYodoAdsLibrary::OnRewardedAdError.ExecuteIfBound(Error);
	});
}

JNI_METHOD void Java_com_ninevastudios_yodoads_YodoAds_OnRewardedAdClosed(JNIEnv* env, jclass clazz)
{
	AsyncTask(ENamedThreads::GameThread, [=]() {
		UYodoAdsLibrary::OnRewardedAdClosed.ExecuteIfBound();
	});
}

JNI_METHOD void Java_com_ninevastudios_yodoads_YodoAds_OnRewardedAdRewardEarned(JNIEnv* env, jclass clazz)
{
	AsyncTask(ENamedThreads::GameThread, [=]() {
		UYodoAdsLibrary::OnRewardedAdRewardEarned.ExecuteIfBound();
	});
}

JNI_METHOD void Java_com_ninevastudios_yodoads_YodoAds_OnInterstitialAdOpened(JNIEnv* env, jclass clazz)
{
	AsyncTask(ENamedThreads::GameThread, [=]() {
		UYodoAdsLibrary::OnInterstitialAdOpened.ExecuteIfBound();
	});
}

JNI_METHOD void Java_com_ninevastudios_yodoads_YodoAds_OnInterstitialAdError(JNIEnv* env, jclass clazz, jstring error)
{
	FString Error = YAJavaConvertor::FromJavaString(error);

	AsyncTask(ENamedThreads::GameThread, [=]() {
		UYodoAdsLibrary::OnInterstitialAdError.ExecuteIfBound(Error);
	});
}

JNI_METHOD void Java_com_ninevastudios_yodoads_YodoAds_OnInterstitialAdClosed(JNIEnv* env, jclass clazz)
{
	AsyncTask(ENamedThreads::GameThread, [=]() {
		UYodoAdsLibrary::OnInterstitialAdClosed.ExecuteIfBound();
	});
}
#endif
