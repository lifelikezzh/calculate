//
// Created by lifelikezzh on 2025/10/19.
//
#include "clip.h"
#include <math.h>
#include <ctype.h>
void clip(const char *caculator, int *digit, char *signal) {
    int cnt=0;
    int cnt1=0;
    int plusOne=0;
    int useThis=1;
    for (int i=0;caculator[i-1]!='=';i++) {
        if (isdigit(caculator[i])!=0) {
            cnt++;
            useThis=0;
        }else if (isdigit(caculator[i])==0 && useThis==1) {
            signal[cnt1]=caculator[i];
            cnt1++;
        }else {
            if (cnt==0){plusOne=1;}
            while (cnt>0) {
                digit[cnt1]+=(caculator[i-cnt]-48)*pow(10,cnt-1);
                cnt--;
            }
            signal[cnt1+1]=caculator[i];
            if (plusOne==1){cnt1+=1;}else{cnt1+=2;}
            plusOne=0;
        }
    }
}