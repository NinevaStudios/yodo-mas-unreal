//
//  Yodo1MasNetworkPlacement.h
//  Yodo1MasCore
//
//  Created by ZhouYuzhen on 2020/12/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Yodo1MasNetworkPlacement : NSObject

@property(nonatomic, copy) NSString *network_code;
@property(nonatomic, copy) NSString *price_type;
@property(nonatomic, assign) double price;
@property(nonatomic, copy) NSString *extra_params;

@end

NS_ASSUME_NONNULL_END
