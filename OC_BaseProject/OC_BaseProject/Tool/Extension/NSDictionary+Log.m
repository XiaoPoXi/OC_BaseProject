//
//  NSDictionary+Log.m
//  pro1
//
//  Created by JoySang on 2020/11/28.
//  Copyright © 2020 YaoTiao. All rights reserved.
//

#import "NSDictionary+Log.h"

@implementation NSDictionary (Log)
/**
 *  输出正常NSDictionary的中文
 */
- (NSString *)descriptionWithLocale:(id)locale indent:(NSUInteger)level
{
    NSMutableString *strM = [NSMutableString stringWithString:@"{\n"];

    [self enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
        [strM appendFormat:@"\t%@ = %@;\n", key, obj];
    }];

    [strM appendString:@"}\n"];

    return strM;
}
@end
@implementation NSArray (Log)

/**
 *  输出正常NSArray的中文
 */

- (NSString *)descriptionWithLocale:(id)locale indent:(NSUInteger)level
{
    NSMutableString *strM = [NSMutableString stringWithString:@"(\n"];

    [self enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
        [strM appendFormat:@"\t%@,\n", obj];
    }];

    [strM appendString:@")"];

    return strM;
}
@end
