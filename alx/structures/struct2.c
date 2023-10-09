#include <stdio.h>

typedef struct {
	int passing;
	int dribbling;
	int shooting;
	int stamina;
	int pace;
	int strength;
	int fitness;
}Player;

int main(void)
{
	Player neymar = {85, 97, 95, 99, 85, 89, 87};
	Player *ptr;
	
	ptr = &neymar;

	printf("Player: Neymar\n");
	printf("\n");
	printf("Passing: %d\n", ptr->passing);
	printf("Dribbling: %d\n", ptr->dribbling);
	printf("Shooting: %d\n", ptr->shooting);
	printf("Stamina: %d\n", ptr->stamina);
	printf("Pace: %d\n", ptr->pace);
	printf("Strength: %d\n", ptr->strength);
	printf("Fitness: %d\n", ptr->fitness);
	printf("\n");
	printf("This player is an ELITE FOOTBALLER, One of the BEST in the world\n");

	return (0);
}
