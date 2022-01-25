//
//  Yodo1Mas.h
//  FBSDKCoreKit
//
//  Created by ZhouYuzhen on 2020/12/3.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Yodo1MasAdEvent.h"
#import "Yodo1MasAdBuildConfig.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^Yodo1MasInitSuccessful)(void);
typedef void (^Yodo1MasInitFail)(Yodo1MasError *);
typedef void (^Yodo1MasAdCallback) (Yodo1MasAdEvent *);

@protocol Yodo1MasAdDelegate <NSObject>

@optional
- (void)onAdOpened:(Yodo1MasAdEvent *)event;
- (void)onAdClosed:(Yodo1MasAdEvent *)event;
- (void)onAdError:(Yodo1MasAdEvent *)event error:(Yodo1MasError *)error;

@end

@protocol Yodo1MasRewardAdDelegate <NSObject, Yodo1MasAdDelegate>

@optional
- (void)onAdRewardEarned:(Yodo1MasAdEvent *)event;

@end

@protocol Yodo1MasInterstitialAdDelegate <NSObject, Yodo1MasAdDelegate>

@end

@protocol Yodo1MasBannerAdDelegate <NSObject, Yodo1MasAdDelegate>

@end

@interface Yodo1Mas : NSObject

@property (nonatomic, assign, readonly) BOOL isInit;
@property (nonatomic, assign) BOOL isGDPRUserConsent;
@property (nonatomic, assign) BOOL isCOPPAAgeRestricted;
@property (nonatomic, assign) BOOL isCCPADoNotSell;
@property (nonatomic, weak) id<Yodo1MasRewardAdDelegate> rewardAdDelegate;
@property (nonatomic, weak) id<Yodo1MasInterstitialAdDelegate> interstitialAdDelegate;
@property (nonatomic, weak) id<Yodo1MasBannerAdDelegate> bannerAdDelegate;

+ (Yodo1Mas *)sharedInstance;
+ (NSString *)sdkVersion;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (void)setAdBuildConfig:(Yodo1MasAdBuildConfig *)buildConfig;

- (void)initWithSuccessful:(Yodo1MasInitSuccessful)successful fail:(Yodo1MasInitFail)fail;
- (void)initWithAppId:(NSString *)appId successful:(Yodo1MasInitSuccessful)successful fail:(Yodo1MasInitFail)fail DEPRECATED_MSG_ATTRIBUTE("Please use initWithAppKey:(NSString *)appKey successful:(Yodo1MasInitSuccessful)successful fail:(Yodo1MasInitFail)fail");
- (void)initWithAppKey:(NSString *)appKey successful:(Yodo1MasInitSuccessful)successful fail:(Yodo1MasInitFail)fail;
- (NSArray *)getBannerAdapter;

- (BOOL)isRewardAdLoaded;
/**
 *  Show the ad, if the ad is already loaded
*/
- (void)showRewardAd;
/**
 * Show the ad, if the ad is already loaded
 * @param placement custom ad slot
*/
- (void)showRewardAdWithPlacement:(NSString *)placement;
//- (void)dismissRewardAdvert;

- (BOOL)isInterstitialAdLoaded;
/**
 *  Show the ad, if the ad is already loaded
*/
- (void)showInterstitialAd;
/**
 * Show the ad, if the ad is already loaded
 * @param placement custom ad slot
*/
- (void)showInterstitialAdWithPlacement:(NSString *)placement;
//- (void)dismissInterstitialAd;

- (BOOL)isBannerAdLoaded;
- (void)showBannerAd;
/**
 * Show the ad, if the ad is already loaded
 * @param placement custom ad slot
 */
- (void)showBannerAdWithPlacement:(NSString * __nullable)placement;
/**
 *
 * Show the ad, if the ad is already loaded
 * @param align banner alignment, align = vertical | horizontal
 *              vertical:
 *              Yodo1Mas.BannerTop
 *              Yodo1Mas.BannerBottom
 *              Yodo1Mas.BannerVerticalCenter
 *              horizontal:
 *              Yodo1Mas.BannerLeft
 *              Yodo1Mas.BannerRight
 *              Yodo1Mas.BannerHorizontalCenter
 *
 */
- (void)showBannerAdWithAlign:(Yodo1MasAdBannerAlign)align;

/**
 *
 * Show the ad, if the ad is already loaded
 * @param align banner alignment, align = vertical | horizontal
 *              vertical:
 *              Yodo1Mas.BannerTop
 *              Yodo1Mas.BannerBottom
 *              Yodo1Mas.BannerVerticalCenter
 *              horizontal:
 *              Yodo1Mas.BannerLeft
 *              Yodo1Mas.BannerRight
 *              Yodo1Mas.BannerHorizontalCenter
 * @param offset horizontal offset and vertical offset, offset.x > 0, the banner will move to the right. offset.x < 0, the banner will move to the left, offset.y > 0, the banner will move to the bottom. offset.y < 0, the banner will move to the top
 */
- (void)showBannerAdWithAlign:(Yodo1MasAdBannerAlign)align offset:(CGPoint)offset;
/**
 *
 * Show the ad, if the ad is already loaded
 * @param placement custom ad slot
 * @param align banner alignment, align = vertical | horizontal
 *              vertical:
 *              Yodo1Mas.BannerTop
 *              Yodo1Mas.BannerBottom
 *              Yodo1Mas.BannerVerticalCenter
 *              horizontal:
 *              Yodo1Mas.BannerLeft
 *              Yodo1Mas.BannerRight
 *              Yodo1Mas.BannerHorizontalCenter
 * @param offset horizontal offset and vertical offset,  offset.x > 0, the banner will move to the right. offset.x < 0, the banner will move to the left, offset.y > 0, the banner will move to the bottom. offset.y < 0, the banner will move to the top
 *
 */
- (void)showBannerAdWithPlacement:(NSString * __nullable)placement align:(Yodo1MasAdBannerAlign)align offset:(CGPoint)offset;
- (void)dismissBannerAd;
/**
 * hide banner ads
 * @param destroy if destroy == YES, the ads displayed in the next call to showBanner are different. if destroy == NO, the ads displayed in the next call to showBanner are same
*/
- (void)dismissBannerAdWithDestroy:(BOOL)destroy;

@end

NS_ASSUME_NONNULL_END
