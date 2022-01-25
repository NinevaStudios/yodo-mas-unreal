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
@property(nonatomic, copy) NSString *price_type; // auto manual
@property(nonatomic, copy) NSString *extra_params;
@property(nonatomic, assign) CGFloat price; // 如果price_type = auto，则price=0; 如果price_type = manual，则price有值

@end

NS_ASSUME_NONNULL_END
