#include <stdio.h>

struct point {

	int x, y;
};

typedef struct months {

	char first[50];
	char second[50];
	char third[50];
	char fourth[50];
} ember;

int main(void)
{
	ember mber_months = {"september", "october", "november", "december"};
	ember* str = &mber_months; /*synchronization takes place here*/

	printf("these are the ember months: %s ==> %s ==> %s ==> %s\n", str->first, str->second, str->third, str->fourth); /*access & manipilation*/

	struct point new = {1,2};

	struct point* ptr = &new;
	
	printf("these are the co-ordinates for x and y respectively: %d & %d\n", ptr->x, ptr->y);

	return (0);
}
