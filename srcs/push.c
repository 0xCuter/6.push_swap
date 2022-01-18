/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:31:26 by scuter            #+#    #+#             */
/*   Updated: 2022/01/17 13:36:01 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_op(t_stack **from, t_stack **to)
{
	t_stack	*first;

	first = *from;
	if (first->next)
		first->next->prev = NULL;
	*from = first->next;
	first->next = *to;
	if (first->next)
		first->next->prev = first;
	*to = first;
}

void	push(char id, t_data *data)
{
	if (id == 'a')
	{
		if (!data->stack_b)
			return ;
		push_op(&data->stack_b, &data->stack_a);
		write(1, "pa\n", 3);
	}
	else if (id == 'b')
	{
		if (!data->stack_a)
			return ;
		push_op(&data->stack_a, &data->stack_b);
		write(1, "pb\n", 3);
	}
}
