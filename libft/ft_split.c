/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpasqui <chpasqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:21:38 by chpasqui          #+#    #+#             */
/*   Updated: 2024/10/21 14:53:31 by chpasqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}	
	}
	return (count);
}

static int	ft_word_length(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**free_tab(char **tab, int i)
{
	while (i > 0)
	{
		free(tab[i - 1]);
		i--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		len;
	int		i;

	tab = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = ft_word_length(s, c);
			tab[i] = ft_substr(s, 0, len);
			if (!tab[i])
				return (free_tab(tab, i));
			i++;
			s += len;
		}
	}
	tab[i] = NULL;
	return (tab);
}

/*#include <stdio.h>

int	main(void)
{
	char const s[] = "hello let's try";
	char	c;
	char	**word;
	int	i;

	c = 32;
	word = ft_split(s, c);
	i = 0;
	while (word[i] != NULL)
	{
		printf("%s\n", word[i]);
		i++;
	}
	i = 0;
	while (word[i])
	{
		free(word[i]);
		i++;
	}
	free(word);
	return (0);
}*/