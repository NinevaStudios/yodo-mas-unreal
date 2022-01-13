// Copyright (c) 2022 Nineva Studios

#include "YodoAds.h"

#include "Developer/Settings/Public/ISettingsModule.h"
#include "Engine/Engine.h"

#include "YodoAdsLog.h"

#define LOCTEXT_NAMESPACE "FYodoAdsModule"

void FYodoAdsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FString PluginName = "YodoAds";

	YodoAdsSettings = NewObject<UYodoAdsSettings>(GetTransientPackage(), "YodoAdsSettings", RF_Standalone);
	YodoAdsSettings->AddToRoot();

	// Register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "YodoAds",
			LOCTEXT("RuntimeSettingsName", "Yodo Ads"),
			LOCTEXT("RuntimeSettingsDescription", "Configure Yodo Ads"),
			YodoAdsSettings);
	}
}

void FYodoAdsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "YodoAds");
	}

	if (!GExitPurge)
	{
		// If we're in exit purge, this object has already been destroyed
		YodoAdsSettings->RemoveFromRoot();
	}
	else
	{
		YodoAdsSettings = nullptr;
	}
}

UYodoAdsSettings* FYodoAdsModule::GetSettings() const
{
	return YodoAdsSettings;
}

#undef LOCTEXT_NAMESPACE

DEFINE_LOG_CATEGORY(LogYodoAds);
	
IMPLEMENT_MODULE(FYodoAdsModule, YodoAds)