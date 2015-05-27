//
//  main.m
//  SamleC
//
//  Created by allamaprabhu on 6/2/14.
//  Copyright (c) 2014 Oracle. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "string.h"

int getMin(int *array,int len);

int main(int argc, const char * argv[])
{
    int N;
    scanf("%d",&N);
    int a[N];
    if (N<1 || N>1000) {
        return 0;
    }
    for (int i =0; i<N ; i++) {
        scanf("%d",&a[i]);
        if (a[i]<1 || a[i]>1000) {
            return 0;
        }
    }
    
    int ct=0;
    do {
        int min = getMin(a, N);
        if (min == 0) {
            break;
        }
        else {
            ct=0;
            for (int i =0 ; i<N ; i++)
            {
                
                a[i]=a[i]-min;
                if (a[i]>=0) {
                    ct++;
                }
            }
        }
        printf("%d\n",ct);
    } while (ct > 1);
    
    return 0;
}

int getMin(int *array,int len)
{
    int min = 0;
    for (int i=0; i<len; i++) {
        if (array[i]>0) {
            if ((min == 0 && array[i]>0) || (array[i] < min)) {
                min=array[i];
            }
        }
    }
    return min;
}
