#include <stdlib.h>

static char *trim_space(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	return str;
}

static int get_word_count(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i] != '\0')
	{
		if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && (str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1] != '\n' && str[i + 1] != '\0'))
			count++;
		i++;
	}
	return count + 1;
}

static char *get_word(char *str)
{
	int len = 0;
	while (str[len] != '\0' && str[len] != ' ' && str[len] != '\t' && str[len] != '\n')
		len++;

	char *new_str = malloc(sizeof(char) * len);

	int i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';

	return new_str;
}

static int get_next_word_count(char *str)
{
	int i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	return i;
}

char **ft_split(char *str)
{
	str = trim_space(str);
	int word_count = get_word_count(str);
	char **strings = malloc(sizeof(char *) * word_count + 1);

	if (word_count == 1)
	{
		strings[0] = NULL;
		strings[1] = NULL;
		return strings;
	}

	int i = 0;
	while (i < word_count)
	{
		strings[i] = get_word(str);
		str = str + get_next_word_count(str);
		i++;
	}
	strings[i] = NULL;
	return strings;
}
