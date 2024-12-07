#include "minitalk.h"

void print_b(int n)
{
    
    int i = 7;
    while (i >= 0)
    {
        printf("%d ",( n >> i) & 1);
        i--;
    }
}

int main()
{
    int i = 0;

    int j = i | 3 << 2;

    print_b(1 << 2);  
    printf("\n");  
    print_b(i);  
    printf("\n");  
    print_b(j);    
    return (0);
    
}