#include <stdio.h>


struct mystructure {

	int age;
	char my_name;
};

struct variables {

	char country;
	int population;
};

struct height {

	int tall_men;
	int short_men;
};

struct days {

	int _long;
	int _brief;
};

int main(void)
{
	struct days autumn;

	autumn._long = 15;
	autumn._brief = 19;

	struct height student;

	student.tall_men = 300;
	student.short_men = 350;

	printf("the height of tall students is %d\n", student.tall_men);
	printf("the height of short students is %d\n", student.short_men);

	printf("there are %d long days in autumn\n", autumn._long);
	printf("there are %d short days in autumn\n", autumn._brief);

	return (0);
}


