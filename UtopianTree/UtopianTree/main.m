//
//  main.m
//  UtopianTree
//
//  Created by allamaprabhu on 7/15/14.
//
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[])
{
    int T;
    scanf("%d",&T);
    int tests[T];
    for (int i = 0; i < T; i++) {
        scanf("%d",&tests[i]);
    }
    for (int i=0 ; i<T; i++) {
        int lenth =1;
        for (int j=0; j<tests[i]; j++) {
            if (j%2==0) {
                lenth = lenth*2;
            }
            else {
                lenth = lenth+1;
            }
        }
        printf("%d\n",lenth);
    }
    return 0;
}

