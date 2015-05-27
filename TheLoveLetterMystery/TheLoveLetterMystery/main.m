//
//  main.m
//  TheLoveLetterMystery
//
//  Created by allamaprabhu on 7/17/14.
//
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[])
{

    int T;
    scanf("%d",&T);
    char words[T][250];
    for (int i= 0; i < T ; i++) {
        scanf("%s",words[i]);
    }
    for (int i = 0; i < T; i++) {
        int j = 0;
        int len = strlen(words[T]);
        int diff = 0;
        //Odd
        if (len %2) {
            j = len/2;
            while (words[i][j] != '\0') {
                int mirrorIndex = (len-j)-1;
                char mirrorElem = words[i][mirrorIndex];

                
                
                if (mirrorElem == words[i][j]) {
                    <#statements#>
                }
                j++;
            }

        }
        else //even
        {
        }
    }
    return 0;
}

