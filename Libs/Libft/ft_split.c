/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:10:24 by jsebasti          #+#    #+#             */
/*   Updated: 2022/09/26 18:25:24 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	sum;
	int	in_word;

	sum = 0;
	in_word = 0;
	while (*str != '\0')
	{
		if (*str != c && in_word == 0)
		{
			++sum;
			in_word = 1;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (sum);
}

static int	word_len(const char *str, int i, char c)
{
	int		len;

	len = 0;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char	**malloc_error(char **new, int j)
{
	while (j >= 0)
	{
		free(new[j]);
		--j;
	}
	free(new);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		i;
	char	**new;

	new = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_words(s, c))
	{
		while (s[i] == c)
			i++;
		new[j] = ft_substr(s, i, word_len(s, i, c));
		if (!new[j])
			return (malloc_error(new, j));
		i += word_len(s, i, c);
		++j;
	}
	new[j] = 0;
	return (new);
}
