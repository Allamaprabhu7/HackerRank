//
//  main.c
//  IsFibo
//
//  Created by allamaprabhu on 11/18/14.
//  Copyright (c) 2014 Oracle. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    scanf("%d",&t);
    if (t<=100000) {
        double a[t];
        for (int i = 0; i<t; i++) {
            scanf("%lf",&a[i]);
            if (a[i] > 10000000000) {
                break;
            }
        }
        for (int i = 0; i < t; i++) {
            double bfp = 5*a[i]*a[i] + 4;
            double bfn = 5*a[i]*a[i] - 4;
            
            double bfpq = sqrt(bfp);
            double bfnq = sqrt(bfn);
            
            if ((floor(bfpq) == bfpq) || (floor(bfnq) == bfnq)) {
                printf("IsFibo\n");
            }
            else {
                printf("IsNotFibo\n");
            }
        }
        
    }
    return 0;
}
