//
//  Yodo1MasAdMobAdapter.h
//  FBSDKCoreKit
//
//  Created by ZhouYuzhen on 2020/12/3.
//

#if __has_include(<Yodo1MasCore/Yodo1MasAdapterBase.h>)
#import <Yodo1MasCore/Yodo1MasAdapterBase.h>
#else
#import "Yodo1MasAdapterBase.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class GADRequest;
@interface Yodo1MasAdMobAdapter : Yodo1MasAdapterBase

+ (CGSize)getAdaptiveSizeWithWidth:(CGFloat)width;
+ (GADRequest *)buildRequest;

@property (nonatomic, assign, readonly) BOOL isMax;

@end

NS_ASSUME_NONNULL_END
