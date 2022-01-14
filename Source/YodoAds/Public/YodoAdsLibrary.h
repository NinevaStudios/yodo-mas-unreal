// Copyright (c) 2022 Nineva Studios

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

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

	UFUNCTION(BlueprintPure, Category = "Yodo Ads")
	static UYodoAdsBanner* MakeBannerAd();

	static FYAVoidDelegate OnInitializeSuccess;
	static FYAErrorDelegate OnInitializeError;

	static const ANSICHAR* YodoAdsClassName;
};