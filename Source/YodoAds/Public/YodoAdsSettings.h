// Copyright (c) 2022 Nineva Studios

#pragma once

#include "Engine/EngineTypes.h"

#include "YodoAdsSettings.generated.h"

UCLASS(Config = Engine, DefaultConfig)
class YODOADS_API UYodoAdsSettings : public UObject
{
	GENERATED_BODY()

public:

	/** Whether the application targets audience of 13 years and under. */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Meta = (DisplayName = "App targets children under 13 years."))
	bool bTargetsKids = false;
};