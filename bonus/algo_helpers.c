/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:27:25 by mjabri            #+#    #+#             */
/*   Updated: 2026/01/10 16:32:31 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	indexing(t_list *stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		count;

	tmp = stack_a;
	while (tmp)
	{
		count = 0;
		tmp2 = stack_a;
		while (tmp2)
		{
			if (tmp->content > tmp2->content)
				count++;
			tmp2 = tmp2->next;
		}
		tmp->index = count;
		tmp = tmp->next;
	}
}

int	pos(t_list *stack_b)
{
	int		pos;
	t_list	*tmp;

	pos = 0;
	while (stack_b)
	{
		tmp = stack_b;
		while (tmp)
		{
			if (stack_b->index < tmp->index)
				break ;
			tmp = tmp->next;
		}
		if (tmp == NULL)
			return (pos);
		stack_b = stack_b->next;
		pos++;
	}
	return (pos);
}
