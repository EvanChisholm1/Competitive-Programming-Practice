#include<stdio.h>
#include<string.h>

int getDigit(int num, int digit) {
    int currentNum = num;
    for(int i = 0; i < digit - 1; i++) { 
        currentNum = currentNum / 10;
    }

    return currentNum % 10;
}

int getInstruction(int num) {
    int d1 = getDigit(num, 5);
    int d2 = getDigit(num, 4);
    int sum = d1 + d2;
    char direction[10];

    // if(sum == 0) {
    //     strcpy(direction, "prev");
    // }
    if(sum % 2 == 0) {
        strcpy(direction, "right");
    } else {
        strcpy(direction, "left");
    }

    int steps = num % 1000;

    printf("%s %d\n", direction, steps);
    return 0;
}

int main() {

    char previousDir[10];

    while(1) {
        int num;
        scanf("%d", &num);
        if(num == 99999) {
            break;
        }

        int d1 = getDigit(num, 5);
        int d2 = getDigit(num, 4);
        int sum = d1 + d2;
        char direction[10];

        if(sum == 0) {
            strcpy(direction, previousDir);
        } else if(sum % 2 == 0) {
            strcpy(direction, "right");
        } else {
            strcpy(direction, "left");
        }

        strcpy(previousDir, direction);

        int steps = num % 1000;

        printf("%s %d\n", direction, steps);
    }
    return 0; 
}
