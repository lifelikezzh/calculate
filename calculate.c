//
// Created by lifelikezzh on 2025/10/21.
//

#include "calculate.h"
#include <string.h>
//#include "isLegal.h"
//#include "factorial.h"
#include "clip.h"
#include "PracticalTools.h"
#include "ConvertDecimals.h"
#include "bracket.h"
#include "TurntoChar.h"
void correctConsecutiveplusAndminusSigns_lite(double *digit, char *signal, int length) {
    /*for (int i=0;i<length;i++) {
        if ((signal[i]=='+'||signal[i]=='-') && (signal[i+1]=='+'||signal[i+1]=='-')) {
            int plusnum=0,minusnum=0;
            for (int t=i;(signal[t]=='+' || signal[t]=='-');t++) {
                if (signal[t]=='+'){plusnum++;}
                else{minusnum++;}
            }
            if (minusnum%2!=0) {
                delstr(signal,i,i+plusnum+minusnum-1,length);
                digit[i+plusnum+minusnum]*=-1;
                delint(digit,i,i+plusnum+minusnum-1,length);
            }else {
                delstr(signal,i,i+plusnum+minusnum-1,length);
                delint(digit,i,i+plusnum+minusnum-1,length);
            }
        }
    }*/
    if (signal[0]=='+') {
        delstr(signal,0,0,length);
        delnum(digit,0,0,length);
    }
    else if(signal[0]=='-') {
        delstr(signal,0,0,length);
        delnum(digit,0,0,length);
        digit[0]*=-1;
    }
}
void calculate(char *caculator,double *digit,char *signal,char *output) {
    int length=strlen(caculator);
    //假设经过检验
    clip(caculator,digit,signal);
    ConvertDecimals(digit,signal,length);
    bracket(digit,signal,length);
    correctConsecutiveplusAndminusSigns_lite(digit,signal,length);
    negative(digit, signal,0,length);
    int multiplyDividenum=count(signal,'*',0,length+1)+count(signal,'/',0,length+1);
    int i=0,j=0;
    for (i=0;i<multiplyDividenum;i++) {
        for (j=0;j<=length;j++) {
            if (signal[j]=='*') {
                digit[j-1]=digit[j-1]*digit[j+1];
                delstr(signal,j,j+1,length);
                delnum(digit,j,j+1,length);
                break;
            }else if (signal[j]=='/') {
                digit[j-1]=digit[j-1]/digit[j+1];
                delstr(signal,j,j+1,length);
                delnum(digit,j,j+1,length);
                break;
            }
        }
    }
    double sum=0;
    int intsum=0,doublesum=0;
    for (i=0;i<length;i+=2) {
        sum+=digit[i];
    }
    intsum=(int)sum;
    doublesum=(sum-intsum)*1000;

    TurntoChar(output,intsum,doublesum);

}