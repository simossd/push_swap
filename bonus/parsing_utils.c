/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:36:14 by mjabri            #+#    #+#             */
/*   Updated: 2026/01/10 16:33:20 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	set_check(char c)
{
	return (((c >= '0' && c <= '9') || c == '+' || c == '-' || c == ' '));
}

int	set_valid(char c)
{
	return (c == '+' || c == '-' || c == ' ' || c == '\0');
}

int	invalid(char const *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (-1);
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && (set_valid(str[i + 1])) != 0)
			return (-1);
		if ((str[i] >= '0' && str[i] <= '9') && (set_valid_2(str[i + 1]) == 1))
			return (-1);
		i++;
	}
	i = 0;
	return (0);
}

int	check_count_words(char const *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (invalid(str) == -1)
		return (-1);
	while (str[i])
	{
		if (set_check(str[i]) != 1)
			return (-1);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i + 1] && str[i] != ' ' && str[i + 1] == ' ')
			count++;
		i++;
		if (str[i] == '\0' && str[i - 1] != ' ' && str[i - 1])
			count++;
	}
	return (count);
}

int	dupcheck(t_list *numbers)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!numbers)
		return (-1);
	tmp = numbers;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2->content == tmp->content)
				return (-1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
// 5 functions
