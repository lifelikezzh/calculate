#include <stdio.h>
#include "calculate.h"
int main() {
    double digit[100]={0};
    char calculator[100]={0};
    char signal[100]={0};
    char output[100]={0};
    scanf("%s",calculator);
    calculate(calculator,digit,signal,output);

}