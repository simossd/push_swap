/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:36:17 by mjabri            #+#    #+#             */
/*   Updated: 2026/01/03 14:08:17 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = tmp->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	write(1, "sb\n", 3);
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp_a;
	t_list	*a_head;
	t_list	*tmp_b;

	if (!*stack_a)
		return ;
	tmp_a = (*stack_a)->next;
	a_head = (*stack_a);
	(*stack_a) = tmp_a;
	tmp_b = (*stack_b);
	(*stack_b) = a_head;
	a_head->next = tmp_b;
	write(1, "pb\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp_b;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp_b = (*stack_b);
	while (tmp_b->next)
		tmp_b = tmp_b->next;
	tmp_b->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	rrb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp2;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = (*stack_b);
	while (temp->next->next)
		temp = temp->next;
	temp2 = temp->next;
	temp->next = NULL;
	temp2->next = (*stack_b);
	(*stack_b) = temp2;
	write(1, "rrb\n", 4);
}
// 4 fcuntions
