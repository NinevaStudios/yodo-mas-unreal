//
//  Yodo1MasInitData.h
//  Yodo1MasCore
//
//  Created by ZhouYuzhen on 2020/12/3.
//

#import <Foundation/Foundation.h>
#import "Yodo1MasInitConfig.h"
#import "Yodo1MasNetworkConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface Yodo1MasInitData : NSObject

@property(nonatomic, copy) NSString *app_id;
@property(nonatomic, copy) NSString *app_key;
@property(nonatomic, copy) NSString *app_name;
@property(nonatomic, copy) NSString *country;
@property(nonatomic, strong) Yodo1MasInitConfig *mas_init_config;
@property(nonatomic, strong) Yodo1MasNetworkConfig *ad_network_config;
@property (nonatomic, copy) NSString *bundle_id;
@property (nonatomic, assign) int test_mode;
@property (nonatomic, assign) NSInteger test_device;

@end

NS_ASSUME_NONNULL_END
