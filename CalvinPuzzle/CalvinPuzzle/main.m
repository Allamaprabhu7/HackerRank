//
//  main.m
//  CalvinPuzzle
//
//  Created by allamaprabhu on 7/15/14.
//
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[])
{
    int N,T;
    
    scanf("%d %d",&N,&T);
    int width[N];
    
    for (int k=0; k < N ; k++) {
        scanf("%d",&width[k]);
    }
    
    int test[T][2];
    for (int i = 0; i < T; i++) {
        scanf("%d%d",&test[i][0],&test[i][1]);
    }
    
    int output[T];
    for (int l = 0; l < T; l++) {
        int i = test[l][0];
        int j = test[l][1];
        int min = 3;
        for (int k = i; k <= j; k++) {
            if (width[k]<min)
            {
                min = width[k];
            }
        }
        output[l]=min;
        printf("%d\n",output[l]);
    }
    return 0;
}

