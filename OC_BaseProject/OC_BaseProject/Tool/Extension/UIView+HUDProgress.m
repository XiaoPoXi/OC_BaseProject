//
//  UIView+HUDProgress.m
//
//  Created by JoySang on 2017/6/28.
//  Copyright © 2017年 JoySang. All rights reserved.
//

//#import <MBProgressHUD/MBProgressHUD.h>
#import "UIView+HUDProgress.h"
#import "MBProgressHUD.h"

#define HUDProgressSrcName(file) [@"HUDProgress.bundle" stringByAppendingPathComponent:file]

@implementation UIView (HUDProgress)

static const NSTimeInterval kMinHideTime = 1.5f;

// 计算文字长度,字符越长显示越久
- (NSTimeInterval)calculateHideTime:(NSString *)text
{
    return text.length * 0.05 + kMinHideTime;
}

- (MBProgressHUD *)hudWithModel:(MBProgressHUDMode)mode
{
    MBProgressHUD *hud = [[MBProgressHUD alloc] initWithView:self];
    hud.mode = mode;
    hud.bezelView.style = MBProgressHUDBackgroundStyleSolidColor;
    hud.animationType = MBProgressHUDAnimationFade;
    hud.bezelView.layer.cornerRadius = 2.0f;
    hud.margin = 10.0f;
    
    hud.bezelView.backgroundColor = [UIColor colorWithWhite:0 alpha:0.8];
    hud.label.font = FontPFRegular(12);
    hud.label.textColor = UIColorFromHex(0xffffff);
    
    return hud;
}

#pragma mark - Only Text status
- (void)showToastText:(NSString *)text afterDelay:(NSTimeInterval)delay
{
    [self dismissHUD];
    MBProgressHUD *hud = [self hudWithModel:MBProgressHUDModeText];
    [self addSubview:hud];
    
    hud.label.text = text;
    hud.userInteractionEnabled = NO;
    
    [hud showAnimated:YES];
    [hud hideAnimated:YES afterDelay:delay];
}

- (void)showToastText:(NSString *)text
{
    [self showToastText:text afterDelay:[self calculateHideTime:text]];
}

- (void)showWGQToastText:(NSString *)text
{
    [self dismissHUD];
    MBProgressHUD *hud = [[MBProgressHUD alloc] initWithView:self];
    hud.mode = MBProgressHUDModeText;
    hud.bezelView.style = MBProgressHUDBackgroundStyleSolidColor;
    hud.animationType = MBProgressHUDAnimationFade;
    hud.bezelView.layer.cornerRadius = 2.0f;
    hud.margin = 10.0f;
    hud.bezelView.backgroundColor = [UIColor colorWithWhite:0 alpha:0.8];
    hud.label.font = FontPFRegular(12);
    hud.label.textColor = UIColorFromHex(0xffffff);
    [hud setOffset:CGPointMake(0, -70)];
    [self addSubview:hud];
    
    hud.label.text = text;
    hud.userInteractionEnabled = NO;
    
    [hud showAnimated:YES];
    [hud hideAnimated:YES afterDelay:text.length * 0.05 + kMinHideTime];
}

#pragma mark - Indicator status
- (void)showIndicatorWithText:(NSString *)text
{
    [self dismissHUD];
    
    [UIActivityIndicatorView appearanceWhenContainedInInstancesOfClasses:@[[MBProgressHUD class]]].activityIndicatorViewStyle = UIActivityIndicatorViewStyleWhite;
    [UIActivityIndicatorView appearanceWhenContainedInInstancesOfClasses:@[[MBProgressHUD class]]].color = UIColorFromHex(0xffffff);
    MBProgressHUD *hud = [self hudWithModel:MBProgressHUDModeIndeterminate];
    [self addSubview:hud];
    
    hud.label.text = text;
    [hud showAnimated:YES];
}

#pragma mark - Success status
- (void)showSuccessWithText:(NSString *)text
{
//    UIImage *image = [UIImage imageNamed:HUDProgressSrcName(@"hud_succeed")];
    UIImage * image = [UIImage imageNamed:@"xg_su"];
    UIImageView *customView = [[UIImageView alloc] initWithImage:image];
    
    [self showWithCustomView:customView text:text];
}

#pragma mark - Error status
- (void)showErrorWithText:(NSString *)text
{
//    UIImage *image = [UIImage imageNamed:HUDProgressSrcName(@"hud_failed")];
    UIImage * image = [UIImage imageNamed:@"xg_fa"];
    UIImageView *customView = [[UIImageView alloc] initWithImage:image];
    
    [self showWithCustomView:customView text:text];
}

#pragma mark - Custom View
- (void)showWithCustomView:(UIView *)customView text:(NSString *)text
{
    [self dismissHUD];
    MBProgressHUD *hud = [self hudWithModel:MBProgressHUDModeCustomView];;
    [self addSubview:hud];
    
    hud.customView = customView;
    
    // 需要在custom之后设置字体和颜色
    hud.detailsLabel.font = FontPFRegular(12);
    hud.detailsLabel.textColor = UIColorFromHex(0xffffff);
    hud.detailsLabel.text = text;
    
    [hud showAnimated:YES];
    [hud hideAnimated:YES afterDelay:[self calculateHideTime:text]];
}

#pragma mark - dismiss
- (void)dismissHUD
{
    [MBProgressHUD hideHUDForView:self animated:YES];
}

@end
