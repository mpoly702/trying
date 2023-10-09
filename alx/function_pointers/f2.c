#include "main.h"

int main(void)
{
	/*declare a function pointer that point to the above functions*/
	int total;
	int sub;

	arithmetic = &add;
	ret = &subtract;
	
	total = arithmetic(5, 3);
	printf("Total: %d\n\n", total);
	
	sub = ret(7, 2);
	printf("Subtraction total: %d\n\n", sub);

	return(0);
}
