#include<stdio.h>

int swap(char *books, int posA, int posB) {
    char tempA = books[posA];
    char tempB = books[posB];
    books[posA] = tempB;
    books[posB] = tempA;
    // printf("A: %c B: %c\n", tempA, tempB);
}

int main() {
    char books[500000];
    scanf("%s", books);
    printf("%s\n", books);
    swap(books, 1, 2);
    books[0] = 0;
    printf("%s\n", books);
    return 0;
}
