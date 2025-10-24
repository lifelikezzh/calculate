//
// Created by lifelikezzh on 2025/10/22.
//
#include "PracticalTools.h"
#include "TurntoChar.h"
#include <math.h>
void TurntoChar(char *output,int intsum,int doublesum) {
    int cintsum=figure(intsum);
    int cdoublesum=figure(doublesum);
    int i=0;
    for (;cintsum>0;cintsum--,i++) {
        output[i]=intsum/(int)pow(10,cintsum-1)+48;
        intsum%=(int)pow(10,cintsum-1);
    }
    output[i]='.';
    i++;
    for (;cdoublesum>0;cdoublesum--,i++) {
        output[i]=doublesum/(int)pow(10,cdoublesum-1)+48;
        doublesum%=(int)pow(10,cdoublesum-1);
    }
    output[i]='\0';
}