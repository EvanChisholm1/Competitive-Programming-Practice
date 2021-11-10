#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *heights = malloc(n * sizeof(int));

    for(int i = 0; i < n + 1; i++) {
        int h;
        scanf("%d", &h);
        heights[i] = h;
    }

    float totalArea = 0;

    for(int i = 0; i < n; i++) {
        int w;
        int leftH = heights[i];
        int rightH = heights[i + 1];
        scanf("%d", &w);
        printf("%d %d\n", leftH, rightH);

        int triangleHeight = leftH - rightH;
        if(triangleHeight < 0) triangleHeight = triangleHeight * -1;
        float triangleArea = w * triangleHeight / 2;
        printf("%f\n", triangleArea);

        int rectHeight;
        if(leftH > rightH) rectHeight = rightH;
        else rectHeight = leftH;

        int rectArea = rectHeight * w;
        float pieceArea = (float)rectArea + triangleArea;

        totalArea += pieceArea;
    }

    printf("%f\n", totalArea);

    free(heights);
    return 0;
}
