#include <stdio.h>
#include <stdlib.h>

int main(void)
{
char *z = "Army";
printf("Before:%s\n", z);

char **y;/*THIS POINTER NEEDS AN ADDRESS FROM WHERE IT WILL POINTS TO HIS DESTINATION ADDRESS*/

/*allocate memory for y*/
y =(char **)malloc(sizeof(char *));

*y = z;/*if you want to sync a variable to a pointer u use &. IF U WANT TO SYNC A POINTER TO A POINTER U DONT NEED &*/
printf("%s\n", *y);

free(y);
return (0);
}
