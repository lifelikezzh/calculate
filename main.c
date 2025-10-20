#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "isLegal.h"
#include "factorial.h"
#include "clip.h"
#include "delarr.h"
void correctConsecutiveplusAndminusSigns(int *digit, char *signal, int length) {
    for (int i=0;i<length;i++) {
        if ((signal[i]=='+'||signal[i]=='-') && (signal[i+1]=='+'||signal[i+1]=='-')) {

        }
    }
}
int main(void) {
    char caculator[]="-123+20*(10-10)/2=";
    int digit[100]={0};
    char signal[100]={0};
    int length=strlen(caculator);
    //假设经过检验
    clip(caculator,digit,signal);
    //delint(digit,0,3,length);

}