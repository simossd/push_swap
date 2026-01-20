/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 10:05:40 by mjabri            #+#    #+#             */
/*   Updated: 2026/01/10 17:25:57 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	algo(t_list **stack_a)
{
	char	*str;
	t_list	*stack_b;
	int		b_check;

	stack_b = NULL;
	str = get_next_line(0);
	while (str)
	{
		if (instructions(stack_a, &stack_b, str) != 1)
		{
			get_next_line(123456789);
			free(str);
			list_free(*stack_a);
			(*stack_a) = NULL;
			list_free(stack_b);
			ft_exit();
		}
		if (str != NULL)
			free(str);
		str = get_next_line(0);
	}
	b_check = list_count(stack_b);
	list_free(stack_b);
	return (b_check);
}

int	aorb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
			return (9);
		if (str[i] == 'b')
			return (-9);
		i++;
		if (i > 2)
			return (0);
	}
	return (0);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	return (0);
}

void	list_free(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (list)
	{
		list = list->next;
		free(tmp);
		tmp = list;
	}
}

int	list_count(t_list *stack)
{
	int		count;
	t_list	*temp;

	temp = stack;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
