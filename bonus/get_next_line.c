/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:57:35 by mjabri            #+#    #+#             */
/*   Updated: 2026/01/10 16:33:05 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*gnl(char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] == '\n')
		str = ft_calloc(i + 2);
	if (src[i] == '\0')
		str = ft_calloc(i + 1);
	if (!str)
		return (free(src), NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		str[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		str[i++] = '\n';
	}
	str[i] = '\0';
	return (str);
}

char	*ft_rread(char *str, ssize_t fd)
{
	char	*buffer;
	ssize_t	i;

	if (!str)
		str = ft_calloc(1);
	if (!str)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(str), NULL);
	i = 1;
	while ((new_line_search(buffer) != 1) && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free(str), free(buffer), NULL);
		buffer[i] = '\0';
		str = ft_strnjoin(str, buffer);
		if (!str)
			return (free(buffer), NULL);
	}
	if (str[0] == '\0')
		return (free(str), free(buffer), NULL);
	return (free(buffer), str);
}

char	*get_next_line(int fd)
{
	static char	*folder;
	char		*str;

	if (fd == 123456789)
	{
		free(folder);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	folder = ft_rread(folder, fd);
	if (!folder)
		return (NULL);
	str = gnl(folder);
	if (!str)
		return (free(folder), NULL);
	folder = ft_line(folder);
	if (!folder)
		return (free(str), NULL);
	return (str);
}
