#include <stdio.h>

int main() {
    int i=0;
    char str[] = "Hello world";
    printf("Original string: %s\n", str);
    printf("AND with 127: ");
    while(str[i] != '\0')
        printf("%c", str[i++] & 127);
    printf("\n");
    printf("OR with 127: ");
    i=0;
    while(str[i] != '\0')
        printf("%c", str[i++] | 127);
    printf("\n");

    printf("XOR with 127: ");
    i=0;
    while(str[i] != '\0')
        printf("%c", str[i++] ^ 127);
    printf("\n");

    return 0;
}
