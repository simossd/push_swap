/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:27:10 by mjabri            #+#    #+#             */
/*   Updated: 2026/01/10 17:28:17 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	int		arg_index;
	char	**str;
	int		num_index;
	t_list	*stack_a;

	arg_index = 1;
	stack_a = NULL;
	if (ac < 2)
		return (0);
	while (arg_index < ac)
	{
		num_index = 0;
		str = ft_split(av[arg_index++]);
		if (!str)
			return (list_free(stack_a), ft_exit(), 1);
		while (str[num_index])
		{
			if (ft_atoi(str[num_index]) > 2147483647)
				return (list_free(stack_a), ft_free(str),
					ft_exit(), 1);
			add_back(&stack_a, new_node(ft_atoi(str[num_index++])), str);
		}
		ft_free(str);
	}
	return (pusher(stack_a));
}

int	pusher(t_list *stack_a)
{
	int	b_check;

	if (dupcheck(stack_a) == -1)
	{
		list_free(stack_a);
		ft_exit();
	}
	indexing(stack_a);
	b_check = algo(&stack_a);
	if (((list_sort(stack_a)) == 0) && (b_check == 0))
		ok();
	else
		ko();
	list_free(stack_a);
	return (0);
}

int	list_sort(t_list *stack_a)
{
	t_list	*temp;

	while (stack_a)
	{
		temp = stack_a;
		while (temp)
		{
			if (temp->index < stack_a->index)
				return (-1);
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}
