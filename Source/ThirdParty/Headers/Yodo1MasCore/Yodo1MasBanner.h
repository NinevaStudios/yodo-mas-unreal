//
//  Yodo1MasBanner.h
//  Yodo1MasCore
//
//  Created by 周玉震 on 2021/1/6.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Yodo1MasCommon.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, Yodo1MasAdBannerAlign) {
    Yodo1MasAdBannerAlignLeft = 1,
    Yodo1MasAdBannerAlignHorizontalCenter = 1 << 1,
    Yodo1MasAdBannerAlignRight = 1 << 2,
    Yodo1MasAdBannerAlignTop = 1 << 3,
    Yodo1MasAdBannerAlignVerticalCenter = 1 << 4,
    Yodo1MasAdBannerAlignBottom = 1 << 5
};

typedef NS_ENUM(NSInteger, Yodo1MasBannerAdSize)  {
    Yodo1MasBannerAdSizeBanner, // 320 * 50
    Yodo1MasBannerAdSizeLargeBanner, // 320 * 100
    Yodo1MasBannerAdSizeIABMediumRectangle, // 300 * 250
    Yodo1MasBannerAdSizeSmartBanner,
    Yodo1MasBannerAdSizeAdaptiveBanner
};

@interface Yodo1MasBanner : NSObject

+ (CGSize)sizeFromAdSize:(Yodo1MasBannerAdSize)size;
+ (CGSize)pixelsFromAdSize:(Yodo1MasBannerAdSize)size;
+ (BOOL)isPad;
+ (UIViewController *)viewController:(UIView *)banner;

@end

NS_ASSUME_NONNULL_END
