//
//  Yodo1MasCommon.h
//  Pods
//
//  Created by ZhouYuzhen on 2020/12/17.
//

#ifndef Yodo1MasCommon_h
#define Yodo1MasCommon_h

#import "Yodo1MasBanner.h"

#define kNotificationYodo1MasSdkInit @"Yodo1MasSdkInit"

typedef NS_ENUM(NSInteger, Yodo1MasAdType) {
    Yodo1MasAdTypeReward = 1,
    Yodo1MasAdTypeInterstitial = 2,
    Yodo1MasAdTypeBanner = 3
};

typedef NS_ENUM(NSInteger, Yodo1MasAdEventCode) {
    Yodo1MasAdEventCodeError = -1,
    Yodo1MasAdEventCodeOpened = 1001,
    Yodo1MasAdEventCodeClosed = 1002,
    Yodo1MasAdEventCodeLoaded = 1003,
    Yodo1MasAdEventCodeRewardEarned = 2001
};

typedef NS_ENUM(NSInteger, Yodo1MasAdPriceType) {
    Yodo1MasAdPriceTypeNone,
    Yodo1MasAdPriceTypeMediation,
    Yodo1MasAdPriceTypeBidding
};

typedef NS_ENUM(NSInteger, Yodo1MasErrorCode) {
    Yodo1MasErrorCodeUnknown = -1,
    
    Yodo1MasErrorCodeConfigNetwork = -100000, //No WIFI/4G or Request Timeout
    Yodo1MasErrorCodeConfigGet = -100501, //Data parsing failed
    
    Yodo1MasErrorCodeAppKeyIllegal = -400000, //Invalid AppKey or Wrong AppKey
    Yodo1MasErrorCodeAppKeyUnverified = -400001, //AppKey Bundle ID Admob ID not match please check your app profile
    
    Yodo1MasErrorCodeAdConfigNull = -600000, // Wrong ad type call.Please check your app profile on MAS to ensure you have selected the correct ad type.
    Yodo1MasErrorCodeAdUninitialized = -600001, // Ad adapter error
    Yodo1MasErrorCodeAdNoLoaded = -600200, // Ad not avaliable,no cache
    Yodo1MasErrorCodeAdShowFail = -600201, //Ad not avaliable,unable to show
    Yodo1MasErrorCodeAdLoadFail = -600202, // Ad download failed
    Yodo1MasErrorCodeAdBannerSizeNotSupport = -600203, // Ad size not supported
    Yodo1MasErrorCodeMultipleBannerNotSupport = -600204 // background configuration not support multiple banner
};


#endif /* Yodo1MasCommon_h */
