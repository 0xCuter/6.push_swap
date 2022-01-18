/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:31:46 by scuter            #+#    #+#             */
/*   Updated: 2022/01/17 13:36:01 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_op(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	last = stack_last(*stack);
	*stack = first->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	(*stack)->prev = NULL;
}

void	rotate(char id, t_data *data)
{
	if (id == 'a')
	{
		if (!data->stack_a || !data->stack_a->next)
			return ;
		rotate_op(&data->stack_a);
		write(1, "ra\n", 3);
	}
	else if (id == 'b')
	{
		if (!data->stack_b || !data->stack_b->next)
			return ;
		rotate_op(&data->stack_b);
		write(1, "rb\n", 3);
	}
}
