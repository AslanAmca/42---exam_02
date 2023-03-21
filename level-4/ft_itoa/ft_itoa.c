#include <stdlib.h>

static int get_len(long number)
{
	int len = 0;
	if (number == 0)
		return 1;
	if (number < 0)
	{
		len++;
		number = -number;
	}
	while (number >= 1)
	{
		number = number / 10;
		len++;
	}
	return len;
}

char *ft_itoa(int nbr)
{
	int i = 0;
	long number = nbr;
	int len = get_len(number);

	char *string = malloc(sizeof(char) * (len + 1));
	string[len] = '\0';
	len--;

	if (number < 0)
	{
		string[i] = '-';
		i++;
		number = -number;
	}
	while (len >= i)
	{
		string[len] = number % 10 + '0';
		number = number / 10;
		len--;
	}

	return string;
}
