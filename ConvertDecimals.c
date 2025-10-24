//
// Created by lifelikezzh on 2025/10/20.
//
#include "math.h"
#include "PracticalTools.h"
#include "ConvertDecimals.h"
void ConvertDecimals(double *digit,char *signal,int length) {
    int i=0;
    for (i=0;i<length;i++) {
        if (signal[i]=='.') {
            digit[i-1]+=digit[i+1]*pow(10,-1*figure(digit[i+1]));
            delstr(signal,i,i+1,length);
            delnum(digit,i,i+1,length);
        }
    }
}