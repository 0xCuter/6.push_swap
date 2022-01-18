/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:02:58 by scuter            #+#    #+#             */
/*   Updated: 2022/01/18 10:27:12 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	r_rotate_op(t_stack **stack)
{
	t_stack	*first;

	first = *stack;
	*stack = stack_last(*stack);
	(*stack)->next = first;
	first->prev = *stack;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

void	r_rotate(char id, t_data *data)
{
	if (id == 'a')
	{
		if (!data->stack_a || !data->stack_a->next)
			return ;
		r_rotate_op(&data->stack_a);
		write(1, "rra\n", 4);
	}
	else if (id == 'b')
	{
		if (!data->stack_b || !data->stack_b->next)
			return ;
		r_rotate_op(&data->stack_b);
		write(1, "rrb\n", 4);
	}
}
