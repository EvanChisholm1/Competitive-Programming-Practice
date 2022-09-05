#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main() {
    int h = 0;
    int v = 0;
    
    int isGoing = 1;

    while(isGoing == 1){
        char c = getchar();
        if(c == *"V") {
            v++;
        } else if(c == *"H") {
            h++;
        } else if(c == *"\n") {
            isGoing = 0;
        }
    }

    if(v % 2 == 0 && h % 2 == 0) {
        printf("1 2\n");
        printf("3 4\n");
    }

    if(v % 2 == 0 && h % 2 == 1) {
        printf("3 4\n");
        printf("1 2\n");
    }

    if(v % 2 == 1 && h % 2 == 1) {
        printf("4 3\n");
        printf("2 1\n");
    }

    if(v % 2 == 1 && h % 2 ==0) {
        printf("2 1\n");
        printf("4 3\n");
    }
}
