/*
// Dipole Length Calculator
// Console Version
// By Michael Geraghty
// Go to malexty.com for more information
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float halfFoot;
float halfMetre;
float fullFoot;
float fullMetre;
float freq;

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Dipole Length Calculator for Amateur Radio\n");
		printf("By Michael Geraghty 2018\n\n");
		printf("You have to enter a frequency!\n");
		printf("Usag: dlengthc frequency\n");
	} else if (argc > 2)
	{
		printf("Dipole Length Calculator for Amateur Radio\n");
		printf("By Michael Geraghty 2018\n\n");
		printf("You can only enter one frequency!\n");
		printf("Usage: dlengthc frequency\n");
	} else
	{
		freq = atof(argv[1]);
		fullMetre = 143 / freq;
		fullFoot = 468 / freq;
		halfMetre = fullMetre / 2;
		halfFoot = fullFoot / 2;
		printf("Dipole Length Calculator for Amateur Radio\n");
		printf("By Michael Geraghty 2018\n\n");
		printf("Length of Each Element - Metre (0--------0) ");
		printf("%f", halfMetre);
		printf(" m\n");
		printf("Length of Each Element - Foot (0--------0) ");
		printf("%f", halfFoot);
		printf(" ft\n");
		printf("Length of total dipole - Metre (0--------00--------0) ");
		printf("%f", fullMetre);
		printf(" m\n");
		printf("Length of total dipole - Foot (0--------00--------0) ");
		printf("%f", fullFoot);
		printf(" ft\n");
	}
	return 0;
}
