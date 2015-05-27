//
//  main.c
//  LoanlyInteger
//
//  Created by allamaprabhu on 11/27/14.
//  Copyright (c) 2014 Oracle. All rights reserved.
//

#include <stdio.h>
#define K_FOUND -1
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    scanf("%d",&n);
    if (n && n<=100 && (n%2)) {
        int a[n];
        for (int i = 0; i<n; i++) {
            scanf("%d",&a[i]);
            if (a[i] > 100 || a[i]<0) {
                return 0;
            }
        }
        for (int i = 0; i<n; i++) {
            if (a[i] == K_FOUND) {
                continue;
            }
            for (int j = i+1; j<n; j++) {
                if (a[j]==K_FOUND) {
                    continue;
                }
                else if (a[i]==a[j]) {
                    a[i]=K_FOUND;
                    a[j]=K_FOUND;
                }
            }
        }
        for (int i = 0; i<n; i++) {
            if (a[i] != K_FOUND) {
                printf("%d\n",a[i]);
            }
        }
        
    }
    return 0;
}
