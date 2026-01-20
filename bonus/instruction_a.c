/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:36:20 by mjabri            #+#    #+#             */
/*   Updated: 2026/01/10 17:01:17 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp_a;

	if (!*stack_a || !(*stack_a)->next)
		return (1);
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp_a = (*stack_a);
	while (tmp_a->next)
		tmp_a = tmp_a->next;
	tmp_a->next = tmp;
	tmp->next = NULL;
	return (1);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;
	t_list	*b_head;
	t_list	*tmp_a;

	if (!*stack_b)
		return (1);
	tmp_b = (*stack_b)->next;
	b_head = (*stack_b);
	(*stack_b) = tmp_b;
	tmp_a = (*stack_a);
	(*stack_a) = b_head;
	b_head->next = tmp_a;
	return (1);
}

int	sa(t_list **stack_a)
{
	t_list	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return (1);
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	return (1);
}

int	rra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp2;

	if (!*stack_a || !(*stack_a)->next)
		return (1);
	temp = (*stack_a);
	while (temp->next->next)
		temp = temp->next;
	temp2 = temp->next;
	temp->next = NULL;
	temp2->next = (*stack_a);
	(*stack_a) = temp2;
	return (1);
}
// 4 functions
