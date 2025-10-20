//
// Created by lifelikezzh on 2025/10/19.
//

#include "factorial.h"
int factorial(const int a) {
    int result=1;
    for (int i=1;i<=a;i++) {
        result*=i;
    }
    return result;
}