//
// Created by lifelikezzh on 2025/10/21.
//
#define FIRST 1
#define LAST 0
#include "bracket.h"
#include "PracticalTools.h"
void bracket(double *digit,char *signal,int length) {
    int bracketNum=count(signal,'(',0,length);
    int i=0,j=0,k=0;
    for (i=0;i<bracketNum;i++) {
        int begin=locate(signal,'(',LAST,0,length-1);
        int end=locate(signal,')',FIRST,begin,length-1);
        int multiplyDividenum=count(signal,'*',begin,end+1)+count(signal,'/',begin,end+1);
        for (j=0;j<multiplyDividenum;j++) {
            begin=locate(signal,'(',LAST,0,length-1);
            end=locate(signal,')',FIRST,begin,length-1);
            for (k=begin;k<=end;k++) {
                if (signal[k]=='*') {
                    digit[k-1]=digit[k-1]*digit[k+1];
                    delstr(signal,k,k+1,length);
                    delnum(digit,k,k+1,length);
                    break;
                }else if (signal[k]=='/') {
                    digit[k-1]=digit[k-1]/digit[k+1];
                    delstr(signal,k,k+1,length);
                    delnum(digit,k,k+1,length);
                    break;
                }
            }
        }
        begin=locate(signal,'(',LAST,0,length-1);
        end=locate(signal,')',FIRST,begin,length-1);
        if (signal[begin+1]=='+'){
            delstr(signal,begin+1,begin+1,length);
            delnum(digit,begin+1,begin+1,length);
            end--;
        }
        else if (signal[begin+1]=='-'){
            delstr(signal,begin+1,begin+1,length);
            delnum(digit,begin+1,begin+1,length);
            digit[begin+1]*=-1;
            end--;
        }
        negative(digit, signal,begin,end);
        double sum=0;
        for (j=begin+1;j<end;j+=2) {
            sum+=digit[j];
        }
        digit[begin]=sum;
        signal[begin]=0;
        delstr(signal,begin+1,end,length);
        delnum(digit,begin+1,end,length);
    }

}