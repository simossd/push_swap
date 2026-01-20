/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:36:05 by mjabri            #+#    #+#             */
/*   Updated: 2026/01/10 17:28:03 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*new_node(int num)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = num;
	new->next = NULL;
	return (new);
}

void	add_back(t_list **node_add, t_list *node_add_2, char **str)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!node_add_2)
	{
		list_free(*node_add);
		while (str[i])
			i++;
		ft_free(str);
		ft_exit();
		return ;
	}
	if (!*node_add)
	{
		(*node_add) = node_add_2;
		return ;
	}
	tmp = (*node_add);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node_add_2;
}

long	ft_atoi(char *str)
{
	long	num;
	long	sign;
	long	i;

	sign = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = str[i] - '0' + (num * 10);
		if (num * sign > 2147483647)
			return (2147483649);
		if (num * sign < -2147483648)
			return (2147483649);
		i++;
	}
	return (num * sign);
}

char	**ft_hp(int nb)
{
	char	**args;

	if (nb <= 0)
		return (NULL);
	else
	{
		args = malloc((sizeof(char *) * (nb + 1)));
		if (!args)
			return (NULL);
	}
	return (args);
}

char	**ft_split(char *s)
{
	int		i;
	char	**args;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	args = ft_hp(check_count_words(s));
	if (!args)
		return (NULL);
	while (s[j] && (i < check_count_words(s)))
	{
		while (s[j] == ' ')
			j++;
		args[i] = fill_up(&s[j]);
		if (!args[i++])
			return (ft_free(args), NULL);
		while ((s[j] >= '0' && s[j] <= '9') || s[j] == '+' || s[j] == '-')
			j++;
	}
	args[i] = NULL;
	return (args);
}
