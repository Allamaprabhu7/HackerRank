//
//  main.m
//  AlternatingChars
//
//  Created by allamaprabhu on 11/19/14.
//  Copyright (c) 2014 Oracle. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

int main(int argc, char * argv[]) {
    @autoreleasepool {
//        NSString *str = @"AABBAA";
//        NSString *str = @"BBBB";
//        NSString *str = @"ABABABAB";
//        NSString *str = @"AAABBB";
//        NSString *str = @"ABBBBB";
//         NSString *str = @"ABCDEF";
        char str[100] ;
        scanf("%s",str);
        
        NSMutableString *mStr = [[NSMutableString alloc] initWithCString:str encoding:NSUTF8StringEncoding];
        int  p = 0;
        while (p<([mStr length]-1)) {
            
            unichar first = [mStr characterAtIndex:p];
            unichar second = 0;
            unichar third = 0;
            if (p<([mStr length]-2)) {
                second = [mStr characterAtIndex:p+1];
                third =[mStr characterAtIndex:p+2];
            }
            else {
                if ((p-1) < 0) {
                    break;
                }
                first = [mStr characterAtIndex:p-1];
                second = [mStr characterAtIndex:p];
                third = [mStr characterAtIndex:p+1];
                
            }
            if (first==third) {
                if (first==second) {
                    [mStr deleteCharactersInRange:NSMakeRange(p, 1)];
                }
                else if (second == third) {
                    [mStr deleteCharactersInRange:NSMakeRange(p+1, 1)];
                }
                else {
                    p++;
                    continue;
                }
            }
            else
            {
                if (first == second) {
                    [mStr deleteCharactersInRange:NSMakeRange(p, 1)];
                }
                else if (second == third) {
                    [mStr deleteCharactersInRange:NSMakeRange(p+1, 1)];
                }
                else {
                    p++;
                    continue;
                }
            }
        }
    }
    return 1;
}
