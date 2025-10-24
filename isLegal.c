//
// Created by lifelikezzh on 2025/10/19.
//
#include <ctype.h>
#include "isLegal.h"
int isLegal(const char *caculator, const int length) {
    int i=0;
    for (i=0;i<length-1;i++) {
        if (isdigit(caculator[i])==0 && caculator[i]!='+' && caculator[i]!='-' && caculator[i]!='*' && caculator[i]!='/' && caculator[i]!='(' && caculator[i]!=')' && caculator[i]!='!' && caculator[i]!='@') {
            return -1;
        }
        else if (caculator[i]=='/' && caculator[i+1]=='0') {
            return -1;
        }
    }
    return 0;
}
