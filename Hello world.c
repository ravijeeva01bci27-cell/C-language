#include <stdio.h>
int main() 
{
    char s[100]; // Buffer to store the input string
    scanf("%[^\n]%*c", s);
    // Print the required greeting
    printf("Hello, World!\n");
    printf("%s", s);
    return 0;
}
