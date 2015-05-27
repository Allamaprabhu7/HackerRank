//
//  main.c
//  Chocolate Feast
//
//  Created by allamaprabhu on 11/14/14.
//  Copyright (c) 2014 Oracle. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int t, n, c, m;
    scanf("%d", &t);
    if (t <= 1000) {
        int a[t][3];
        for (int i = 0; i < t; i++) {
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        }
        for (int i = 0; i < t; i++) {
            n = a[i][0];
            c = a[i][1];
            m = a[i][2];
            if (c>=1 && c<=n && m >= 2 && m <= n) {
                int nw = 0;
                int nc = 0;
                nc = (int)(n/c);
                nw = nc;
                while (nw >= m) {
                    int c = (int)(nw/m);
                    nw =  c + (nw%m);
                    nc+=c;
                }
                int answer = nc;
                printf("%d\n",answer);
            }
            else
                break;
        }
    }
    return 0;
}












/*
 // insert code here...
 int t, n, c, m;
 scanf("%d", &t);
 if (t <= 1000) {
 while (t--) {
 scanf("%d%d%d",&n,&c,&m);
 if (n >1 && n<=100000 && c <= n && m >1 && m <= n ) {
 int answer = 0;
 
 int numOfChocs=0,w = 0;
 numOfChocs = (int)(n/c);
 w = numOfChocs;
 
 while (w) {
 if (w >= m) {
 int d = (int)(w / m);
 numOfChocs += d;
 w = d+(w%m);
 }
 else {
 int rem = n%c;
 if (rem) {
 float cw = m/c;
 int leftMoney = cw * w;
 if (leftMoney > c) {
 w = (int)(leftMoney/c);
 numOfChocs = numOfChocs + (int)(leftMoney/c);
 }
 }
 }
 
 if (w < m) {
 break;
 }
 }
 
 answer = numOfChocs;
 printf("%d\n",answer);
 }
 }
 }
 return 0;
*/