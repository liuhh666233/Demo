#include <stdio.h>
#include <string.h>

int strlonger(char *s, char *t)
{
    printf("%lu", strlen(s) - strlen(t));
    return strlen(s) - strlen(t) > 0;
}

int main()
{
    char *s = "hello world";
    char *t = "hello fucking world";
    strlonger(s, t);
    return 0;
}