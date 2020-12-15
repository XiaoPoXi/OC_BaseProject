//
//  UIApplication+Extension.m
//  BWM_iOS
//
//  Created by JoySang on 2019/10/12.
//  Copyright © 2019 JoySang. All rights reserved.
//

#import "UIApplication+Extension.h"

@implementation UIApplication (Extension)
+ (UIWindow *)keyWindow
{
    for (UIWindow *window in [[UIApplication sharedApplication] windows])
    {
        if (window.isKeyWindow)
        {
            return window;
        }
    }
    return [self firstWindow];
}

+ (UIWindow *)firstWindow
{
    return [[[UIApplication sharedApplication] windows] firstObject];
}

+ (UIViewController *)topViewController
{
    return [self topVCWithRootVC:self.keyWindow.rootViewController];
}

+ (UIViewController *)topVCWithRootVC:(UIViewController *)rootVC
{
    if ([rootVC isKindOfClass:[UITabBarController class]])
    {
        UITabBarController *tabBarController = (UITabBarController *)rootVC;
        return [self topVCWithRootVC:tabBarController.selectedViewController];
    }
    else if ([rootVC isKindOfClass:[UINavigationController class]])
    {
        UINavigationController *navigationController = (UINavigationController *)rootVC;
        return [self topVCWithRootVC:navigationController.visibleViewController];
    }
    else if (rootVC.presentedViewController)
    {
        UIViewController *presentedViewController = rootVC.presentedViewController;
        return [self topVCWithRootVC:presentedViewController];
    }
    else
    {
        return rootVC;
    }
}
@end
