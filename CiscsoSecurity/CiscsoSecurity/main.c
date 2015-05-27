//
//  main.c
//  CiscsoSecurity
//
//  Created by allamaprabhu on 4/9/15.
//  Copyright (c) 2015 hackerRank. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, const char * argv[]) {
    char key[1000],xcipher[1000],cipher[1000],plaintxt[1000];
    scanf("%s",key);
    scanf("%s",xcipher);
    
    int lkey = 0,lcipher = 0;
    while (key[++lkey] != '\0');
    while (xcipher[++lcipher] != '\0');

    int k = 0;
    for (int i = 0; i<lcipher/2; i++) {
        char *substr = malloc(sizeof(char)*2);
        memset(substr, xcipher[i*2], sizeof(char));
        memset(substr+1, xcipher[i*2+1], sizeof(char));
        
        unsigned int res =  (unsigned int)strtol(substr, NULL, 16);
        cipher[k] = res;
        k++;
        free(substr);
    }

    lcipher = lcipher/2;
    if (lkey < lcipher) {
        int compReccur = ((int)(lcipher/lkey)-1);
        for (int j = 1 ; j<=compReccur; j++)
        {
            for (int i = 0 ; i<lkey; i++)
            {
                key[(lkey*j)+i]=key[i];
            }
        }
        int delta = lcipher % lkey;
        for (int i = 0; i<delta ; i++) {
            key[(lkey*(compReccur+1))+i] = key[i];
        }
        for (int i = 0; i<lcipher; i++) {
            plaintxt[i]=key[i]^cipher[i];
        }
        plaintxt[lcipher]='\0';
        printf("%s",plaintxt);
    }
    return 0;
}
