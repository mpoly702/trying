#include <stdio.h>

int main() {
    // Write C code here
    int i, j;
    int d;
    
    printf("Enter a number\n");
    scanf("%d", &d);
    
    for (i = 1; i <= d; i++)
    {
        for (j = 1; j <= d; j++)
        {
           if (j <= d - i)
           {
               printf(" ");
           }
           if (j >= d -i)
           {
               printf("# ");
           }
        }
        putchar('\n');
    }

    return 0;
}
