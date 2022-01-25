//
//  Yodo1MasNetworkConfig.h
//  Yodo1MasCore
//
//  Created by ZhouYuzhen on 2020/12/3.
//

#import <Foundation/Foundation.h>
#import "Yodo1MasNetworkAdvert.h"

NS_ASSUME_NONNULL_BEGIN

@interface Yodo1MasNetworkConfig : NSObject

@property(nonatomic, strong) Yodo1MasNetworkAdvert *reward;
@property(nonatomic, strong) Yodo1MasNetworkAdvert *interstitial;
@property(nonatomic, strong) Yodo1MasNetworkAdvert *banner;

@end

NS_ASSUME_NONNULL_END
