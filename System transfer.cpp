
#include "stdafx.h"
#include "stdlib.h"

int main()
{
	int evenPart, system, remaining, counter = -1, limit;
	float fractionalPart;
	char output[30];
	puts("Enter number.");
	scanf_s("%f", &fractionalPart);
	puts("Enter system.");
	scanf_s("%d", &system);
	puts("What accuracy do you require(amount of numerals after '.')?");
	scanf_s("%d", &limit);
	evenPart = fractionalPart;
	fractionalPart -= evenPart;
	while (evenPart != 0)
	{
		counter++;
		remaining = evenPart % system;
		evenPart /= system;
		if (system < 10 || remaining < 10)
			output[counter] = (char)(remaining + '0');
		if (system > 10 && remaining >= 10)
			output[counter] = (char)('A' - 10 + remaining);
	}
	for (int i = counter; i >= 0; i--, counter--)
		printf_s("%c", output[i]);
	printf_s(".");
	while (fractionalPart != 0)
	{
		counter++;
		if (counter == limit - 1)
			break;
		remaining = fractionalPart * system;
		fractionalPart = fractionalPart*system - remaining;
		if (system < 10 || remaining < 10)
			printf_s("%d", remaining);
		if (system > 10 && remaining >= 10)
			printf_s("%c", (char)('A' - 10 + remaining));
	}
	puts("\nDone.");
    return 0;
}

