//
//  Yodo1MasNetworkWaterfall.h
//  Yodo1MasCore
//
//  Created by ZhouYuzhen on 2020/12/3.
//

#import <Foundation/Foundation.h>
#import "Yodo1MasNetworkPlacement.h"

NS_ASSUME_NONNULL_BEGIN

@interface Yodo1MasNetworkWaterfall : NSObject

@property(nonatomic, copy) NSString *network;
@property(nonatomic, strong) NSArray<Yodo1MasNetworkPlacement *> *placements;

@end

NS_ASSUME_NONNULL_END
