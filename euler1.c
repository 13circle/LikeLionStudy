#include <stdio.h>

int main() {
    int max, i, sum;
    for(i = 3, sum = 0, max = 1000; i < max; sum += (!(i % 3) || !(i % 5)) ? i : 0, i++);
    printf("Sum: %d \n", sum);
    return 0;
}