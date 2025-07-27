#include <stdio.h>

int main(void) {
	/* write a program that computes
	   the volume of a sphere with a 10-meter radius 
	   using the formula v = 4/3 * pi * r * r * r
	*/
	int r = 10;
	float volume = 4 / 3 * 3.14 * r * r * r;
	printf("volume: %.2f", volume);
}
