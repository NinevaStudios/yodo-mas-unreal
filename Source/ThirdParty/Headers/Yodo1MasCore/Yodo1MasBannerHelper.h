//
//  Yodo1MasBannerHelper.h
//  Yodo1MasCore
//
//  Created by 周玉震 on 2021/10/27.
//

#import <Foundation/Foundation.h>
#import "Yodo1MasCommon.h"
#import "Yodo1MasBannerAdView.h"

NS_ASSUME_NONNULL_BEGIN
 
@interface Yodo1MasBannerHelper : NSObject

+ (Yodo1MasBannerHelper *)sharedInstance;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (BOOL)isBannerAdLoaded;
- (void)showBannerAdWithPlacement:(NSString * __nullable)placement align:(Yodo1MasAdBannerAlign)align offset:(CGPoint)offset;
- (void)dismissBannerAdWithDestroy:(BOOL)destroy;

- (void)adjustFrame:(Yodo1MasBannerAdView *)banner adPosition:(NSInteger) align offset:(CGPoint) offset;
- (CGFloat)getWidthInPixels:(Yodo1MasBannerAdView *)bannerView;
- (CGFloat)getHeightInPixels:(Yodo1MasBannerAdView *)bannerView;

@end

NS_ASSUME_NONNULL_END
