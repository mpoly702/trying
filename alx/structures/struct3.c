#include <stdio.h>

typedef struct {

	int Passing;
	int Dribbling;
	int Strength;
	int Pace;
	int Accuracy;
}Player;

int main(void)
{
	Player Neymar = {87, 98, 83, 87, 91};
	Player *ptr;

	ptr = &Neymar;

	printf("Player Stat: Neymar  \n\n");
	printf("Passing: %d\n", ptr->Passing);
	printf("Dribbling: %d\n", ptr->Dribbling);
	printf("Strength: %d\n", ptr->Strength);
	printf("Pace: %d\n", ptr->Pace);
	printf("Accuracy: %d\n", ptr->Accuracy);
	printf("\n");
	printf("This Player is ELITE\n\n\n\n");

	Player Mbappe = {85, 87, 88, 97, 91};
	Player *Mbp;

	Mbp = &Mbappe;

	printf("Player Stat: Mbappe  \n\n");
	printf("Passing: %d\n", Mbp->Passing);
	printf("Dribbling: %d\n", Mbp->Dribbling);
	printf("Strength: %d\n", Mbp->Strength);
	printf("Pace: %d\n", Mbp->Pace);
	printf("Accuracy: %d\n", Mbp->Accuracy);
	printf("\n");
	printf("This Player is ELITE\n");

	return(0);
}
