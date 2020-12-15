//
//  UIApplication+Extension.h
//  BWM_iOS
//
//  Created by JoySang on 2019/10/12.
//  Copyright © 2019 JoySang. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIApplication (Extension)
/**
 *  @brief  获取应用程序主窗口
 *
 *  @return 主窗口
 */
+ (UIWindow *)keyWindow;

/**
 *  @brief  获取应用程序第一个窗口
 *
 *  @return 第一个窗口
 */
+ (UIWindow *)firstWindow;

/**
 *  @brief  获取当前最顶部显示的viewController
 *
 *  @return viewController
 */
+ (UIViewController *)topViewController;
@end

NS_ASSUME_NONNULL_END
