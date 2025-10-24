//
// Created by lifelikezzh on 2025/10/19.
//

#ifndef CACULATE_DELARR_H
#define CACULATE_DELARR_H
void delstr(char *arr,int begin,int end,int length);
void delnum(double *arr,int begin,int end,int length);
int figure(int num);
int count(char *signal,char goal,int begin,int end);
int locate(char *signal,char goal,int firstOrlast,int begin,int end);
void negative(double *digit, char *signal,int begin,int end);
#endif //CACULATE_DELARR_H