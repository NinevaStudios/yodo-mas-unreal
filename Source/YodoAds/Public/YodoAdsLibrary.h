// Copyright (c) 2022 Nineva Studios

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

#if PLATFORM_IOS
#include "IOS/YAAdDelegate.h"
#endif

#include "YodoAdsLibrary.generated.h"

USTRUCT(BlueprintType)
struct FYodoAdsConfig
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Yodo Ads")
	bool EnableUserPrivacyDialog = false;

	UPROPERTY(BlueprintReadWrite, Category = "Yodo Ads")
	bool EnableAdaptiveBanner = false;

	UPROPERTY(BlueprintReadWrite, Category = "Yodo Ads")
	FString PrivacyPolicyUrl = "";

	UPROPERTY(BlueprintReadWrite, Category = "Yodo Ads")
	FString UserAgreementUrl = "";
};

DECLARE_DYNAMIC_DELEGATE(FYAVoidDelegate);
DECLARE_DYNAMIC_DELEGATE_OneParam(FYAErrorDelegate, FString, Error);

class UYodoAdsBanner;

UCLASS()
class YODOADS_API UYodoAdsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static void SetConfig(const FYodoAdsConfig& Config);

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads", meta = (AutoCreateRefTerm = "OnSuccess,OnError"))
	static void Initialize(const FYAVoidDelegate& OnSuccess, const FYAErrorDelegate& OnError);

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static void SetGDPR(bool UserConsent);

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static bool IsGDPRUserConsent();

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static void SetCOPPA(bool AgeRestricted);

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static bool IsCOPPAAgeRestricted();

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static void SetCCPA(bool DontSell);

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static bool IsCCPADontSell();

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads", meta = (AutoCreateRefTerm = "OnOpened,OnError,OnClosed,OnRewardEarned"))
	static void SetRewardedAdListener(const FYAVoidDelegate& OnOpened, const FYAErrorDelegate& OnError, const FYAVoidDelegate& OnClosed, const FYAVoidDelegate& OnRewardEarned);

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static bool IsRewardedAdLoaded();

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static void ShowRewardedAd(const FString& Placement = "");

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads", meta = (AutoCreateRefTerm = "OnOpened,OnError,OnClosed"))
	static void SetInterstitialAdListener(const FYAVoidDelegate& OnOpened, const FYAErrorDelegate& OnError, const FYAVoidDelegate& OnClosed);

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static bool IsInterstitialAdLoaded();

	UFUNCTION(BlueprintCallable, Category = "Yodo Ads")
	static void ShowInterstitialAd(const FString& Placement = "");

	UFUNCTION(BlueprintPure, Category = "Yodo Ads")
	static UYodoAdsBanner* MakeBannerAd();

	static FYAVoidDelegate OnInitializeSuccess;
	static FYAErrorDelegate OnInitializeError;

	static FYAVoidDelegate OnRewardedAdOpened;
	static FYAErrorDelegate OnRewardedAdError;
	static FYAVoidDelegate OnRewardedAdClosed;
	static FYAVoidDelegate OnRewardedAdRewardEarned;

	static FYAVoidDelegate OnInterstitialAdOpened;
	static FYAErrorDelegate OnInterstitialAdError;
	static FYAVoidDelegate OnInterstitialAdClosed;

	static const ANSICHAR* YodoAdsClassName;
	
#if PLATFORM_IOS
	static YAInterstitialAdDelegate* InterstitialAdDelegate;
	static YARewardedAdDelegate* RewardedAdDelegate;
#endif
};
