//
// Created by lifelikezzh on 2025/10/19.
//

#include "PracticalTools.h"
void delstr(char *arr,int begin,int end,int length) {
    int i=0;
    for (i=begin;i<length-(end-begin);i++) {
        arr[i]=arr[i+(end-begin)+1];
    }
}
void delnum(double *arr,int begin,int end,int length) {
    int i=0;
    for (i=begin;i<length-(end-begin);i++) {
        arr[i]=arr[i+(end-begin)+1];
    }
}
int figure(int num) {
    int cnt=0;
    if (num<0){num*=-1;}
    while (num!=0) {
        cnt++;
        num/=10;
    }
    return cnt;
}
int count(char *signal,char goal,int begin,int end) {
    int i=0;
    int cnt=0;
    for (i=begin;i<end;i++) {
        if (signal[i]==goal) {
            cnt++;
        }
    }
    return cnt;
}
int locate(char *signal,char goal,int firstOrlast,int begin,int end) {
    int index=0;
    int i=0;
    if (firstOrlast==1) { //first==1
        for (i=end;i>=begin;i--) {
            if (signal[i]==goal){index=i;}
        }
    }else {//end==0
        for (i=begin;i<=end;i++) {
            if (signal[i]==goal){index=i;}
        }
    }
    return index;
}
void negative(double *digit, char *signal,int begin,int end) {
    int i=0;
    for (i=begin;i<=end;i++) {
        if (signal[i]=='-') {
            digit[i+1]*=-1;
        }
    }
}