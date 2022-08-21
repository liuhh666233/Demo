#include <stdio.h>
#include <string.h>

int uadd_ok(unsigned x, unsigned y)
{
    unsigned sum = x + y;
    printf("%u  ", sum);
    return sum >= x;
}

int main()
{
    printf("  %u", uadd_ok(3000000000, 3000000000));
    return 0;
}