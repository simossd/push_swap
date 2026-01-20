/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:36:23 by mjabri            #+#    #+#             */
/*   Updated: 2026/01/10 16:33:09 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	set_valid_2(char c)
{
	return (c == '+' || c == '-');
}

ssize_t	ft_len(char const *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

char	**ft_free(char **s)
{
	int	args;

	args = 0;
	while (s[args])
		free(s[args++]);
	free(s);
	return (NULL);
}

char	*fill_up(char const *s)
{
	int		i;
	int		len;
	char	*str;

	len = ft_len(s);
	if (len <= 0)
		return (NULL);
	i = 0;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (s[i] && s[i] != ' ')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
// 5 functions
