#include<stdio.h>

int getPressure(int b) {
    return 5 * b - 400;
}

int getLevel(int p) {
    if(p > 100) {
        return -1;
    } else if(p < 100) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int b;
    scanf("%d", &b);
    int presure = getPressure(b);
    int level = getLevel(presure);
    printf("%d\n", presure);
    printf("%d\n", level);
    return 0;
}
