//
//  main.c
//  CiscoSecurity_Encoding
//
//  Created by allamaprabhu on 4/10/15.
//  Copyright (c) 2015 hackerRank. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *OMBase32Decode(const char *inputBuffer,
                     size_t length,
                     size_t *outputLength);

char *NewOMBase64Encode(
                        const void *buffer,
                        size_t length,
                        int  separateLines,
                        size_t *outputLength);



int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    scanf("%d",&N);
    if (N>10) return 1;
    char list[N][200];
    for (int i=0; i<N; i++) {
        scanf("%s",list[i]);
    }
    
    for (int i=0; i<N; i++) {
        printf("%s\n",list[i]);
        size_t len = (size_t)strlen(list[i]);
        
        size_t *outbufflen;
        char *decoded = OMBase32Decode(list[i], len, outbufflen);
        char *base64encoded = NewOMBase64Encode(decoded, strlen(decoded), 0, outbufflen);
        printf("%s\n",base64encoded);
        
    }
    
    return 0;
}


static unsigned char base32EncodeLookup[33] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";

#define xxx 33
#define yy 34

static unsigned char base32DecodeLookup[256] =
{
    /*        0   1   2   3   4   5   6   7   8   9 */
    /*000*/  xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*010*/  xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*020*/  xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*030*/  xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*                                        0,  1 */
    /*040*/  xxx, xxx, xxx, 62, xxx, xxx, xxx, xxx, xxx, xxx,
    /*        2,  3,  4,  5,  6,  7,  8,  9         */
    /*050*/  26, 27, 28, 29, 30, 31, xxx, xxx, xxx, xxx,
    /*                            A,  B,  C,  D,  E */
    /*060*/  xxx, yy, xxx, xxx, xxx,  0,  1,  2,  3,  4,
    /*        F,  G,  H,  I,  J,  K,  L,  M,  N,  O */
    /*070*/   5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
    /*        P,  Q,  R,  S,  T,  U,  V,  W,  X,  Y */
    /*080*/  15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
    /*        Z,                          a,  b,  c */
    /*090*/  25, xxx, xxx, xxx, xxx, xxx, xxx,  0,  1,  2,
    /*        d,  e,  f,  g,  h,  i,  j,  k,  l,  m */
    /*100*/   3,  4,  5,  6,  7,  8,  9, 10, 11, 12,
    /*        n,  o,  p,  q,  r,  s,  t,  u,  v,  w */
    /*110*/  13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
    /*        x,  y,  z                             */
    /*120*/  23, 24, 25, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*130*/  xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*140*/  xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*150*/  xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*160*/  xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*170*/  xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*180*/  xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*190*/  xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*200*/  xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*210*/  xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*220*/  xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*230*/  xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*240*/  xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
    /*250*/  xxx, xxx, xxx, xxx, xxx, xxx,
};

#define BINARY_UNIT_SIZE_1 5
#define BASE32_UNIT_SIZE 8
#define OM_NUM_BITS      8

void *OMBase32Decode(const char *inputBuffer,
                     size_t length,
                     size_t *outputLength)
{
    size_t   outputBufferSize    = 0;
    size_t   currentPos          = 0;
    size_t   inputBytesProcessed = 0;
    char    *outputBuffer        = NULL;
    
    if (length == -1)
    {
        length = strlen(inputBuffer);
    }
    
    outputBufferSize = (((length+BASE32_UNIT_SIZE-1)/ BASE32_UNIT_SIZE)*BINARY_UNIT_SIZE_1)+1;
    outputBuffer = (char *)malloc(sizeof(char)*outputBufferSize);
    
    if (outputBuffer == NULL)
        return NULL;
    
    while (inputBytesProcessed < length)
    {
        size_t decodedlen = 0;
        char buffer[BASE32_UNIT_SIZE+1] = "";
        size_t  copysize = ((length - inputBytesProcessed) > BASE32_UNIT_SIZE) ?
        BASE32_UNIT_SIZE : (length - inputBytesProcessed);
        strncpy(buffer, inputBuffer+inputBytesProcessed, copysize);
        buffer[copysize] = '\0';
        
        for (size_t cpos = 0; cpos < copysize; cpos++)
        {
            buffer[cpos] = base32DecodeLookup[inputBuffer[inputBytesProcessed+cpos]];
            if (buffer[cpos] == yy)
            {
                if ((length-inputBytesProcessed) != 8)
                {
                    free(outputBuffer);
                    outputBuffer = NULL;
                    break;
                }
                else
                    buffer[cpos] = '\0';
            } //if block
            else if (buffer[cpos] == xxx)
            {
                free(outputBuffer);
                outputBuffer = NULL;
            }
            else
                decodedlen++;
        } //for loop
        
        inputBytesProcessed += copysize;
        if (outputBuffer == NULL)
        {
            *outputLength = 0;
            break;
        }
        
        if (decodedlen >= 2)
        {
            outputBuffer[currentPos] = (buffer[0] << 3) | (buffer[1] >> 2);
            currentPos++;
        }
        
        if (decodedlen >= 4)
        {
            outputBuffer[currentPos] = (buffer[1] << 6) | (buffer[2] << 1) |
            (buffer[3]>>4);
            currentPos++;
        }
        
        if (decodedlen >= 5)
        {
            outputBuffer[currentPos] = (buffer[3]<<4) | (buffer[4]>>1);
            currentPos++;
        }
        
        if (decodedlen >= 7)
        {
            outputBuffer[currentPos] = (buffer[4] << 7) | (buffer[5] << 2) | (buffer[6]>>3);
            currentPos++;
        }
        
        if (decodedlen == 8)
        {
            outputBuffer[currentPos] = buffer[6] << 5 | buffer[7];
            currentPos++;
        }
    }
    
    if (outputBuffer)
    {
        //outputBuffer[currentPos] = '\0';
        *outputLength = currentPos;
    }
    return outputBuffer;
}



static unsigned char base64EncodeLookup[65] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

//
// Definition for "masked-out" areas of the base64DecodeLookup mapping
//
#define xx 65

//
// Mapping from ASCII character to 6 bit pattern.
//
static unsigned char base64DecodeLookup[256] =
{
    xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx,
    xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx,
    xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, 62, xx, xx, xx, 63,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, xx, xx, xx, xx, xx, xx,
    xx,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, xx, xx, xx, xx, xx,
    xx, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, xx, xx, xx, xx, xx,
    xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx,
    xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx,
    xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx,
    xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx,
    xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx,
    xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx,
    xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx,
    xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx,
};


 
 
 //
 // Fundamental sizes of the binary and base64 encode/decode units in bytes
 //
 #define BINARY_UNIT_SIZE 3
 #define BASE64_UNIT_SIZE 4
 

char *NewOMBase64Encode(
                        const void *buffer,
                        size_t length,
                        int  separateLines,
                        size_t *outputLength)
{
    const unsigned char *inputBuffer = (const unsigned char *)buffer;
    
#define MAX_NUM_PADDING_CHARS 2
#define OUTPUT_LINE_LENGTH 64
#define INPUT_LINE_LENGTH ((OUTPUT_LINE_LENGTH / BASE64_UNIT_SIZE) * BINARY_UNIT_SIZE)
#define CR_LF_SIZE 2
    
    //
    // Byte accurate calculation of final buffer size
    //
    size_t outputBufferSize =
    ((length / BINARY_UNIT_SIZE)
     + ((length % BINARY_UNIT_SIZE) ? 1 : 0))
    * BASE64_UNIT_SIZE;
    if (separateLines)
    {
        outputBufferSize +=
        (outputBufferSize / OUTPUT_LINE_LENGTH) * CR_LF_SIZE;
    }
    
    //
    // Include space for a terminating zero
    //
    outputBufferSize += 1;
    
    //
    // Allocate the output buffer
    //
    char *outputBuffer = (char *)malloc(outputBufferSize);
    if (!outputBuffer)
    {
        return NULL;
    }
    
    size_t i = 0;
    size_t j = 0;
    const size_t lineLength = separateLines ? INPUT_LINE_LENGTH : length;
    size_t lineEnd = lineLength;
    
    while (1)
    {
        if (lineEnd > length)
        {
            lineEnd = length;
        }
        
        for (; i + BINARY_UNIT_SIZE - 1 < lineEnd; i += BINARY_UNIT_SIZE)
        {
            //
            // Inner loop: turn 48 bytes into 64 base64 characters
            //
            outputBuffer[j++] = base64EncodeLookup[(inputBuffer[i] & 0xFC) >> 2];
            outputBuffer[j++] = base64EncodeLookup[((inputBuffer[i] & 0x03) << 4)
                                                   | ((inputBuffer[i + 1] & 0xF0) >> 4)];
            outputBuffer[j++] = base64EncodeLookup[((inputBuffer[i + 1] & 0x0F) << 2)
                                                   | ((inputBuffer[i + 2] & 0xC0) >> 6)];
            outputBuffer[j++] = base64EncodeLookup[inputBuffer[i + 2] & 0x3F];
        }
        
        if (lineEnd == length)
        {
            break;
        }
        
        //
        // Add the newline
        //
        outputBuffer[j++] = '\r';
        outputBuffer[j++] = '\n';
        lineEnd += lineLength;
    }
    
    if (i + 1 < length)
    {
        //
        // Handle the single '=' case
        //
        outputBuffer[j++] = base64EncodeLookup[(inputBuffer[i] & 0xFC) >> 2];
        outputBuffer[j++] = base64EncodeLookup[((inputBuffer[i] & 0x03) << 4)
                                               | ((inputBuffer[i + 1] & 0xF0) >> 4)];
        outputBuffer[j++] = base64EncodeLookup[(inputBuffer[i + 1] & 0x0F) << 2];
        outputBuffer[j++] =	'=';
    }
    else if (i < length)
    {
        //
        // Handle the double '=' case
        //
        outputBuffer[j++] = base64EncodeLookup[(inputBuffer[i] & 0xFC) >> 2];
        outputBuffer[j++] = base64EncodeLookup[(inputBuffer[i] & 0x03) << 4];
        outputBuffer[j++] = '=';
        outputBuffer[j++] = '=';
    }
    outputBuffer[j] = 0;
    
    //
    // Set the output length and return the buffer
    //
    if (outputLength)
    {
        *outputLength = j;
    }
    return outputBuffer;
}
