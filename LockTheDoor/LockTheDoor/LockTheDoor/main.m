//
//  main.m
//  LockTheDoor
//
//  Created by allamaprabhu on 9/11/14.
//  Copyright (c) 2014 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "stdio.h"
static int compare(const void *p1,const void *p2);
static int compare(const void *p1,const void *p2)
{
    int retVal=0;
    if(p2 > p1) {
        retVal=1;
    }
    else if(p1>p2) {
        retVal = -1;
    }
    return retVal;
}


int main()
{
    char key[10];
    scanf("%s",key);
    int len = (int)strlen(key);
    
    mergesort(<#void *#>, <#size_t#>, <#size_t#>, <#int (*)(const void *, const void *)#>)
    if (len>0) {
        
    }
    return 0;
}


