/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:38:45 by scuter            #+#    #+#             */
/*   Updated: 2022/01/17 13:36:01 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_op(t_stack **stack)
{
	t_stack	*first;

	first = *stack;
	*stack = (*stack)->next;
	first->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = first;
	(*stack)->next = first;
	first->prev = *stack;
	(*stack)->prev = NULL;
}

void	swap(char id, t_data *data)
{
	if (id == 'a')
	{
		if (!data->stack_a || !data->stack_a->next)
			return ;
		swap_op(&data->stack_a);
		write(1, "sa\n", 3);
	}
	else if (id == 'b')
	{
		if (!data->stack_b || !data->stack_b->next)
			return ;
		swap_op(&data->stack_b);
		write(1, "sb\n", 3);
	}
}
