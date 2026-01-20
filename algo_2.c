/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:02:45 by mjabri            #+#    #+#             */
/*   Updated: 2026/01/07 19:02:45 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_2(t_list **stack_a, int stack_count)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (stack_count == 2)
		sa(stack_a);
	else if (stack_count == 3)
		algo_trio(stack_a);
	else if (stack_count == 4)
		cuatro_algo(stack_a, &stack_b);
	else
		algo_cinco(stack_a, &stack_b);
}

void	algo_trio(t_list **stack_a)
{
	indexing(*stack_a);
	if ((*stack_a)->index == 2)
		ra(stack_a);
	if ((*stack_a)->next->index == 2)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void	cuatro_algo(t_list **stack_a, t_list **stack_b)
{
	int	count;

	indexing(*stack_a);
	count = 0;
	while (!count)
	{
		if ((*stack_a)->index == 0)
		{
			pb(stack_b, stack_a);
			count++;
		}
		else
			ra(stack_a);
	}
	algo_trio(stack_a);
	pa(stack_a, stack_b);
}

void	algo_cinco(t_list **stack_a, t_list **stack_b)
{
	int	count;

	count = 0;
	while (!(count == 2))
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
		{
			pb(stack_b, stack_a);
			count++;
		}
		else
			ra(stack_a);
	}
	algo_trio(stack_a);
	if ((*stack_b)->index < (*stack_b)->next->index)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
