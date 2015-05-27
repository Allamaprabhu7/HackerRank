//
//  main.m
//  GemStones
//
//  Created by allamaprabhu on 7/16/14.
//
//

#import <Foundation/Foundation.h>


int main(int argc, const char * argv[])
{
    int N;
    scanf("%d",&N);
    char rocks[N][250];
    for (int i=0; i < N; i++) {
        scanf("%s",rocks[i]);
    }
    int fc =0;
    char start ='a';
    for (int i=start; i < (start+26) ; i++) {
        int ct = 0;
        for (int j = 0; j<N ; j++) {
            int k = 0;
            while (rocks[j][k]!= '\0') {
                if (rocks[j][k] ==  (char)i) {
                    ct++;
                    break;
                }
                k++;
            }
        }
        if (ct == N) {
            fc++;
        }
    }
    printf("%d",fc);
    return 0;
}

