// Copyright (c) 2022 Nineva Studios

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#include "YodoAdsSettings.h"

class FYodoAdsModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/**
	 * Singleton-like access to this module's interface.  This is just for convenience!
	 * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	 *
	 * @return Returns singleton instance, loading the module on demand if needed
	 */
	static inline FYodoAdsModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FYodoAdsModule>("YodoAds");
	}

	/**
	 * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	 *
	 * @return True if the module is loaded and ready to use
	 */
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("YodoAds");
	}

	UYodoAdsSettings* GetSettings() const;

private:
	UYodoAdsSettings* YodoAdsSettings;
};
