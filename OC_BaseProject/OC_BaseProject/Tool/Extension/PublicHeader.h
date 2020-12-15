//
//  PublicHeader.h
//  pro1
//
//  Created by JoySang on 2019/9/23.
//  Copyright © 2019 JoySang. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef PublicHeader_h
#define PublicHeader_h

/**************************************************************/



//引用相关头文件
#import <BRPickerView.h>

#define JPUSHAPPKEY @"0c198493d64c4877dabec885"
#define JPUSHID @"JPushID"

#define kWechatAppid @"wx91d05064524a2f5e"
#define kWechatAppSecret @"92ce3f57dcf5c0ab385bca6d8d0155ac"
#define kJVERIFICATIONServicekey @"0c198493d64c4877dabec885"

//通知
#define kNSNotificationNamedAppleLogin @"NSNotificationNamedAppleLogin"//苹果登录通知
#define kNSNotificationNamedWechatLogin @"NSNotificationNamedWechatLogin"//微信登录通知
#define kNSNotificationNamedJverificationLogin @"NSNotificationNamedJverificationLogin"//极光一键登录通知
#define kNSNotificationNamedJverificationBang @"NSNotificationNamedJverificationBang"//极光一键绑定通知
#define kNSNotificationNamedBindLogin @"NSNotificationNamedBindLogin" //绑定之后并登录成功

//图片地址,图片生成
#define kImageUrlQrCodeBackImage @"http://img.jumituangou.com/clientUse/ossimages/usercenter/inviterBg.png"//我的服务,二维码背景图
#define kImageUrlQrCodeImage(uid) [NSString stringWithFormat:@"http://h5.yaotiao.net/#/bus_share/%%2Flogin%%2Flogin%%2F/%@/",uid]  //二维码生成规则

//各类文章id配置
#define kArticleIdYeJiGuiZe @"10"     //店铺业绩--业绩规则文章id
#define kArticleIdShouYiGuiZe @"1"   //累计总收益--收益规则文章id
#define kArticleIdYongHuXieYi @"2"   //用户协议文章id
#define kArticleIdYinSiZhengCe @"3"  //隐私政策文章id
#define kHelpCenterId @"6"          //帮助中心的文章id
#define kSharingEconomyCooperationAgreementId @"4" //可提现金额--共享经济合作协议
#define kStatisticalDescriptionArticleId @"11" //客户排行榜--数据统计说明

#define kLoginUserAgreementUrl @"http://h5.yaotiao.net/#/Setting/Article/2/true"
#define kLoginPrivacyPolicyUrl @"http://h5.yaotiao.net/#/Setting/Article/3/true"


// html文件名
#define kHTMLFileName @"dist"
// app信息key
#define kAppInfo @"AppInfo"

#pragma mark - 屏幕尺寸相关

/// 获取主屏幕的高度
#define kMainScreenHeight                       ([UIScreen mainScreen].bounds.size.height)
/// 获取主屏幕的宽度
#define kMainScreenWidth                        ([UIScreen mainScreen].bounds.size.width)

/// 状态栏的高度
#define kStatusBarHeight                        [UIApplication sharedApplication].statusBarFrame.size.height

/// 状态栏高
#define kStatusBarH  (kStatusBarHeight > 20 ? 44 : 20)

/// navigationBar高度（包括状态栏高度）
#define kNavigationBarH (kStatusBarHeight > 20 ? 88 : 64)
/// tabbar高度（包括底部安全区域）
#define kTabbarH (kStatusBarHeight > 20 ? 83 : 49)
//底部home条
#define kTabbarSafeH (kStatusBarHeight > 20 ? 34 : 0)

// 绘制1个像素的线
#define Single_Pixel_Line                       (1 / [UIScreen mainScreen].scale)
#define Single_Pixel_Line_Offset                ((1 / [UIScreen mainScreen].scale) / 2)

// 16:9 和 4:3 比例值
#define kScale_16_9                             1.777777
#define kScale_9_16                             0.5625
#define kScale_4_3                              1.333333
#define kScale_3_4                              0.75

/**************************************************************/

// 对象强引用 & 弱引用
#define WeakObj(obj)    __weak typeof(obj)      obj##Weak = obj;
#define StrongObj(obj)  __strong typeof(obj)    obj = obj##Weak;

/**************************************************************/

#pragma mark - 创建图片相关
// 创建不带缓存的图片
#define ImageWithFile(named) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:named ofType:nil]]

// 创建带缓存的图片
#define ImageWithName(named) [UIImage imageNamed:named]

/**************************************************************/

#pragma mark - Class相关
#define ClassObj(aClass)        [aClass class]
#define ClassName(aClass)       NSStringFromClass([aClass class])

/**************************************************************/

#pragma mark - 空数据判断

/// 判断对象是否为空或是[NSNull null]
#define IsNilOrNull(_ref)   (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]))
/// 数组是否为空
#define IsArrEmpty(_ref)    (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) || ([(_ref) count] == 0))
/// 字符串是否为空
#define IsStrEmpty(_ref)    (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) || ([(_ref)isEqualToString:@""]))


/**************************************************************/


#pragma mark - 系统相关
// 是否iPad
#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

// 判断当前屏幕是不是4英寸
#define isScreenInch_4  (kMainScreenWidth == 320 && kMainScreenHeight == 568)

/// 获取系统版本
#define DeviceSystemVersion [[UIDevice currentDevice].systemVersion floatValue]

/**************************************************************/
#pragma mark - 多线程相关
/** 提交一个任务在子线程中执行 */
static inline void dispatch_back_thread(void (^block)(void)) {
    if ([NSThread isMainThread]) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),block);
    } else {
        block();
    }
}

/** 提交一个任务在主线程中执行 */
static inline void dispatch_main_thread(void (^block)(void)) {
    if ([NSThread isMainThread]) {
        block();
    } else {
        dispatch_async(dispatch_get_main_queue(), block);
    }
}

/**************************************************************/

#pragma mark - 数组&字典安全操作

/// 数组获取对象
#define ArraySafeObjectAtIndex(array, obj, index); \
@try {\
    obj = [array objectAtIndex:index];\
} @catch(NSException * exception) {\
    NSLog(@"Array object exception:%@",exception);\
} @finally {\
}

/// 数组添加对象
#define ArraySafeAddObject(array, obj); \
@try { \
    [array addObject:obj]; \
} @catch(NSException * exception) { \
    NSLog(@"Array addObject exception:%@",exception); \
} @finally { \
}

/// 数组插入对象
#define ArraySafeInsertObject(array, obj, index); \
@try { \
    [array insertObject:obj atIndex:index]; \
} @catch(NSException * exception) { \
    NSLog(@"Array insertObject exception:%@",exception); \
} @finally { \
}

/// 数组移除对象
#define ArraySafeRemoveObjectAtIndex(array, index); \
@try {\
    [array removeObjectAtIndex:index];\
} @catch(NSException * exception) {\
    NSLog(@"Array remove exception:%@",exception);\
} @finally {\
}

/// 数组替换对象
#define ArraySafeReplaceObjectAtIndex(array, obj, index); \
@try {\
    [array replaceObjectAtIndex:index withObject:obj];\
} @catch(NSException * exception) {\
    NSLog(@"Array replace exception:%@",exception);\
} @finally{\
}

/// 字典设置value
#define DictSafeSetValue(dict, key, obj); \
@try { \
    [dict setValue:obj forKey:key]; \
} @catch(NSException * exception) { \
    NSLog(@"Dict setValue exception:%@",exception); \
} @finally { \
}

/// 字典设置对象
#define DictSafeSetObject(dict, key, obj); \
@try { \
    [dict setObject:obj forKey:key]; \
} @catch(NSException * exception) { \
    NSLog(@"Dict setObject exception:%@",exception); \
} @finally { \
}

/// 字典移除对象
#define DictSafeRemoveObject(dict, key); \
@try { \
    [dict removeObjectForKey:key]; \
} @catch(NSException * exception) { \
    NSLog(@"Dict removeObject exception:%@",exception); \
} @finally { \
}


/**************************************************************/
#pragma mark - 颜色类相关

/// 十六进制值取色(HEX, alpha)
#define UIColorFromHexA(rgbValue, alp)         [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16)) / 255.0 green:((float)((rgbValue & 0xFF00) >> 8)) /255.0 blue:((float)(rgbValue & 0xFF)) / 255.0 alpha:alp]

/// 获取RGB Alpha颜色
#define UIColorFromRGBA(R, G, B, A)             [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]

/// 十六进制值取色(HEX)
#define UIColorFromHex(rgbValue)                UIColorFromHexA(rgbValue, 1.0)

// 获取RGB颜色
#define UIColorFromRGB(R, G, B)                 UIColorFromRGBA(R, G, B, 1.0f)

#pragma mark - 输入框字体大小,颜色
/**************************************************************/

// 常见颜色宏定义
#define ComColor0xf4f4f4            UIColorFromHex(0xf4f4f4)
#define ComColor0xfefefe            UIColorFromHex(0xfefefe)
#define ComColor0x333333            UIColorFromHex(0x333333)
#define ComColor0xeeeeee            UIColorFromHex(0xeeeeee)
#define ComColor0xe6e6e6            UIColorFromHex(0xe6e6e6)
#define ComColor0x666666            UIColorFromHex(0x666666)
#define ComColor0x999999            UIColorFromHex(0x999999)
#define ComColor0xcccccc            UIColorFromHex(0xcccccc)
#define ComColor0xc4c4c4            UIColorFromHex(0xc4c4c4)
#define ComColor0xa8a8a8            UIColorFromHex(0xa8a8a8)

// 字体大小缩放
#define FontSizeScale(size)         size //((kMainScreenWidth / 375) * size)
// 坐标大小缩放
#define CoordXSizeScale(size)       ((kMainScreenWidth / 375) * size)
#define CoordYSizeScale(size)       ((kMainScreenHeight / 667) * size)

#define KIsiPhoneX  ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)


// 苹方字体
#define FontPFThin(fSize)           [UIFont fontWithName:@"PingFangSC-Thin" size:FontSizeScale(fSize)] ?: [UIFont systemFontOfSize:fSize]
#define FontPFLight(fSize)          [UIFont fontWithName:@"PingFangSC-Light" size:FontSizeScale(fSize)] ?: [UIFont systemFontOfSize:fSize]
#define FontPFMedium(fSize)         [UIFont fontWithName:@"PingFangSC-Medium" size:FontSizeScale(fSize)] ?: [UIFont systemFontOfSize:fSize]
#define FontPFRegular(fSize)        [UIFont fontWithName:@"PingFangSC-Regular" size:FontSizeScale(fSize)] ?: [UIFont systemFontOfSize:fSize]
#define FontPFSCBold(fSize)         [UIFont fontWithName:@"PingFangSC-Semibold" size:FontSizeScale(fSize)] ?: [UIFont systemFontOfSize:fSize]
#define FontPFUltralight(fSize)     [UIFont fontWithName:@"PingFangSC-Ultralight" size:FontSizeScale(fSize)] ?: [UIFont systemFontOfSize:fSize]

#endif /* PublicHeader_h */
