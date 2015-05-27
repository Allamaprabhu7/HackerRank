//
//  main.c
//  MaximumSubArray
//
//  Created by allamaprabhu on 2/2/15.
//  Copyright (c) 2015 Oracle. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>


// Define a vector type
typedef struct {
    int size;      // slots used so far
    int capacity;  // total available slots
    int *data;     // array of integers we're storing
} Vector;

int main(int argc, const char * argv[]) {
    
    int T;
    scanf("%d",&T);
    if (T < 1 || T > 10) {
        return 0;
    }
    Vector *list[T];
    for (int i=0; i<T; i++)
    {
        int N = 0;
        scanf("%d",&N);
        if (N < 1 || N > 100000) {
            return 0;
        }
        Vector *numArray = malloc(sizeof(Vector));
        numArray->size = N;
        numArray->data = malloc(N*sizeof(int));
        for (int j = 0; j<N; j++)
        {
            int v = 0;
            scanf("%d",&v);
            if (v < (-10000) || v > 10000) {
                return 0;
            }
            numArray->data[j] = v;
        }
        list[i]=numArray;
        numArray = NULL;
    }

    for (int t = 0; t<T; t++) {
        Vector *numArray = list[t];
        int sumSoFar = 0;
        int maxSumSoFar = 0;
        int totalSum = 0;
        int negSum = -10000;

        for (int i = 0; i< numArray->size; i++) {
            sumSoFar = sumSoFar + numArray->data[i];
            if (sumSoFar < 0) {
                if (sumSoFar>negSum) {
                    negSum = sumSoFar;
                }
                sumSoFar = 0;
            }
            if (maxSumSoFar < sumSoFar) {
                maxSumSoFar = sumSoFar;
            }
            if (numArray->data[i] > 0) {
                totalSum = totalSum + numArray->data[i];
            }
        }
        if (maxSumSoFar == 0 && negSum > -10000) {
            maxSumSoFar = negSum;
            totalSum = maxSumSoFar;
        }
        printf("%d %d\n",maxSumSoFar,totalSum);
    }
    return 0;
}
