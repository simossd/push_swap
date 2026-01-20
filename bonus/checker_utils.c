/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:28:38 by mjabri            #+#    #+#             */
/*   Updated: 2026/01/10 17:28:39 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	apply_b(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp("sb\n", str) == 0)
		return (sb(stack_b));
	if (ft_strcmp("rb\n", str) == 0)
		return (rb(stack_b));
	if (ft_strcmp("pb\n", str) == 0)
		return (pb(stack_b, stack_a));
	if (ft_strcmp("ss\n", str) == 0)
		return (sb(stack_b));
	if (ft_strcmp("rr\n", str) == 0)
		return (rb(stack_b));
	if (ft_strcmp("rrb\n", str) == 0)
		return (rrb(stack_b));
	if (ft_strcmp("rrr\n", str) == 0)
		return (rrb(stack_b));
	return (-1);
}

int	apply_a(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp("sa\n", str) == 0)
		return (sa(stack_a));
	if (ft_strcmp("ra\n", str) == 0)
		return (ra(stack_a));
	if (ft_strcmp("pa\n", str) == 0)
		return (pa(stack_a, stack_b));
	if (ft_strcmp("ss\n", str) == 0)
		return (sa(stack_a));
	if (ft_strcmp("rr\n", str) == 0)
		return (ra(stack_a));
	if (ft_strcmp("rra\n", str) == 0)
		return (rra(stack_a));
	if (ft_strcmp("rrr\n", str) == 0)
		return (rra(stack_a));
	return (-1);
}

int	instructions(t_list **stack_a, t_list **stack_b, char *str)
{
	int	check;
	int	app;

	app = aorb(str);
	check = -1;
	if (app == 9)
		check = apply_a(stack_a, stack_b, str);
	if (app == -9)
		check = apply_b(stack_a, stack_b, str);
	if ((ft_strcmp("ss\n", str) == 0) || (ft_strcmp("rr\n", str) == 0)
		|| (ft_strcmp("rrr\n", str) == 0))
	{
		check = apply_a(stack_a, stack_b, str);
		if (check == -1)
			return (-1);
		check = apply_b(stack_a, stack_b, str);
	}
	return (check);
}
