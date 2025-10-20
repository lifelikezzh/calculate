//
// Created by lifelikezzh on 2025/10/19.
//

#include "delarr.h"
void delstr(char *arr,int begin,int end,int length) {
    for (int i=begin;i<length-(end-begin);i++) {
        arr[i]=arr[i+(end-begin)+1];
    }
}
void delint(int *arr,int begin,int end,int length) {
    for (int i=begin;i<length-(end-begin);i++) {
        arr[i]=arr[i+(end-begin)+1];
    }
}