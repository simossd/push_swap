/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 10:05:40 by mjabri            #+#    #+#             */
/*   Updated: 2026/01/08 08:00:56 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_b(t_list **stack_a, t_list **stack_b)
{
	int	position;
	int	len;

	while (*stack_b)
	{
		len = list_count(*stack_b);
		position = pos(*stack_b);
		if (position < len / 2)
		{
			while (position-- > 0)
				rb(stack_b);
		}
		else
		{
			position = len - position;
			while (position-- > 0)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	algo_a(t_list **stack_a, int chank_n)
{
	t_list	*stack_b;
	int		chunk;
	int		size;

	chunk = chank_n;
	stack_b = NULL;
	if (!*stack_a)
		return ;
	while (*stack_a)
	{
		size = list_count(stack_b);
		if ((*stack_a)->index < size)
		{
			pb(&stack_b, stack_a);
			rb(&stack_b);
		}
		else if ((*stack_a)->index < size + chunk)
			pb(&stack_b, stack_a);
		else
			ra(stack_a);
	}
	algo_b(stack_a, &stack_b);
}

void	algo(t_list **stack_a)
{
	int	chunk;
	int	size;

	if (!*stack_a)
		return ;
	size = list_count(*stack_a);
	if (size <= 100)
		chunk = 15;
	else if (size <= 500)
		chunk = 30;
	else
		chunk = 45;
	if (size <= 5)
		algo_2(stack_a, size);
	else
		algo_a(stack_a, chunk);
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

	if (!stack)
		return (-1);
	temp = stack;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
