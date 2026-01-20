/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 07:51:26 by mjabri            #+#    #+#             */
/*   Updated: 2026/01/10 16:32:57 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*ft_calloc(size_t nmemb)
{
	size_t	i;
	char	*str;

	str = malloc(nmemb);
	if (!str)
		return (NULL);
	i = 0;
	while (i < nmemb)
		str[i++] = 0;
	return (str);
}

size_t	ft_strnlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	new_line_search(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strnjoin(char *src1, char *src2)
{
	char	*str;
	size_t	s1;
	size_t	s2;
	size_t	i;

	str = ft_calloc(ft_strnlen(src1) + ft_strnlen(src2) + 1);
	if (!str)
		return (free(src1), free(src2), NULL);
	i = 0;
	s1 = 0;
	s2 = 0;
	while (src1[s1])
		str[i++] = src1[s1++];
	while (src2[s2])
		str[i++] = src2[s2++];
	str[i] = '\0';
	return (free(src1), str);
}

char	*ft_line(char *str)
{
	size_t		i;
	char		*line;
	size_t		index;

	i = 0;
	index = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc(ft_strnlen(str) - i + 1);
	if (!line)
	{
		return (free(str), NULL);
	}
	if (str[i] != '\0')
		i++;
	while (str[i])
		line[index++] = str[i++];
	line[index] = '\0';
	return (free(str), line);
}
