// Copyright (c) 2022 Nineva Studios

#pragma once

#include "Engine/EngineTypes.h"

#include "YodoAdsSettings.generated.h"

UCLASS(Config = Engine, DefaultConfig)
class YODOADS_API UYodoAdsSettings : public UObject
{
	GENERATED_BODY()

public:

	/** Whether the application targets audience of 13 years and under. Used for different dependencies on Android*/
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Yodo Ads|Android", Meta = (DisplayName = "App targets children under 13 years"))
	bool bTargetsKids = false;

	/** Android App Key from the Yodo console. */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Yodo Ads|Android", Meta = (DisplayName = "Android App Key"))
	FString AndroidAppKey;

	/** Android Admob ID from Admob console. */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Yodo Ads|Android", Meta = (DisplayName = "Android Admob App ID"))
	FString AndroidAdmobAppId;

	/** iOS App Key from the Yodo console. */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Yodo Ads|iOS", Meta = (DisplayName = "iOS App Key"))
	FString iOSAppKey;

	/** iOS Admob ID from Admob console. */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Yodo Ads|iOS", Meta = (DisplayName = "iOS Admob App ID"))
	FString iOSAdmobAppId;
	
	/** Text to be shown to users when requesting User Tracking for personalized ads. */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Yodo Ads|iOS", Meta = (DisplayName = "User Tracking Usage Description"))
	FString UserTrackingUsageDescription;
};
