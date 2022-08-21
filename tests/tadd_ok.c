#include <stdio.h>

int tadd_ok(int x, int y){
    int sum = x + y;
    if (y == -2147483648) {
        int neg_over = x < 0;
        return !neg_over;
    }
    int neg_over = x < 0 && y < 0 && sum >= 0;
    int pos_over = x >=0 && y >=0 && sum < 0;
    return !neg_over && !pos_over;
}

int main(){
    int x = 2;
    int y = -2147483648;
    printf("Result: %d\n", tadd_ok(x, -y));
}