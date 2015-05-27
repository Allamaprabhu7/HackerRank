//
//  main.c
//  FindDigits
//
//  Created by allamaprabhu on 11/18/14.
//  Copyright (c) 2014 Oracle. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    scanf("%d",&t);
    if (t>0 && t<=15) {
        long a[t];
        for (int i = 0; i<t; i++) {
            scanf("%ld",&a[i]);
            if (a[i] > 10000000000) {
                break;
            }
        }
        for (int i = 0; i < t ; i++) {
            long n = a[i];
            long N = n;
            int ct = 0;
            while (n > 0) {
                int rem = n%10;
                n = (long)(n/10);
                if (rem && (N%rem)==0) {
                    ct++;
                }
            }
            printf("%d\n",ct);
        }
    }

    return 0;
}
