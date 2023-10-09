#include <stdio.h>


int main(void)
{
	char str = "Mike Aremu";
	int age = 67;
	printf("the name of the man is %s, he is %d years old", str, age);
}
DECLARING ARRAY OF POINTERS.
int numx = 30;
int numy = 40;
int numz = 10;


int *gift[3]; /*declaring  an array of pointers*/

gift[0] = &numx;
gift[1] = &numy;
gift[2] = &numz;

FUNCTION POINTERS
void (*aremu)(int, char, float);/*this function pointer only points to functions with 3 parm*/


void (*stand)(int);/*this function pointer only points to functions with 1 parameter*/

void (*term)(int, int);/*this function pointer only points to functions with 2 parameters*/
