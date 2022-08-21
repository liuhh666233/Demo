#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t length)
{
    size_t i;
    for (i = 0; i < length; i++)
    {
        printf("%.2x ", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    printf("show_int: \n");
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
    printf("show_float: \n");
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
    printf("show_pointer: \n");
    show_bytes((byte_pointer)&x, sizeof(void *));
}

int main()
{
    const char *s = "abcdef";
    show_bytes((byte_pointer)s, strlen(s));
}   