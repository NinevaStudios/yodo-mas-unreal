//
//  Yodo1MasInitConfig.h
//  Yodo1MasCore
//
//  Created by ZhouYuzhen on 2020/12/3.
//

#import <Foundation/Foundation.h>
#import "Yodo1MasInitMediationInfo.h"
#import "Yodo1MasInitNetworkInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface Yodo1MasInitConfig : NSObject

@property(nonatomic, strong) NSArray<Yodo1MasInitMediationInfo *> *mediation_list;
@property(nonatomic, strong) NSArray<Yodo1MasInitNetworkInfo *> *ad_network_list;

@end

NS_ASSUME_NONNULL_END
