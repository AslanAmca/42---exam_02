int max(int *tab, unsigned int len)
{
	int max = *tab;
	int i = 0;
	while (i <= len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return max;
}
