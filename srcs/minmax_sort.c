/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:09:50 by scuter            #+#    #+#             */
/*   Updated: 2022/01/18 10:26:42 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static int	get_steps(t_stack *stack, t_stack *node)
// {
// 	int	steps;

// 	steps = 0;
// 	while (stack)
// 	{
// 		if (stack == node)
// 			return (steps);
// 		steps++;
// 		stack = stack->next;
// 	}
// 	return (steps);
// }

// static void	minmax(t_data *data)
// {
// 	int	len;
// 	int	steps[4];

// 	while (data->stack_b)
// 	{
// 		len = stack_len(data->stack_b);
// 		steps[0] = get_steps(data->stack_b, stack_smaller(data->stack_b));
// 		steps[1] = get_steps(data->stack_b, stack_bigger(data->stack_b));
// 		steps[2] = len - steps[0] + 1;
// 		steps[3] = len - steps[1] + 1;
// 		if (steps[0] < steps[1] && steps[0] < steps[2] && steps[0] < steps[3])
// 		{
// 			repeat_op(rotate, steps[0], 'b', data);
// 			push('a', data);
// 			rotate('a', data);
// 		}
// 		else if (steps[1] <= steps[2] && steps[1] <= steps[3])
// 		{
// 			repeat_op(rotate, steps[1], 'b', data);
// 			push('a', data);
// 		}
// 		else if (steps[2] < steps[3])
// 		{
// 			repeat_op(r_rotate, steps[2], 'b', data);
// 			push('a', data);
// 			rotate('a', data);
// 		}
// 		else
// 		{
// 			repeat_op(r_rotate, steps[3], 'b', data);
// 			push('a', data);
// 		}
// 	}
// }

static void	minmax(t_data *data, t_stack *bigger, t_stack *smaller)
{
	t_stack	*top;
	t_stack	*bottom;
	int		i;

	top = data->stack_b;
	bottom = stack_last(data->stack_b);
	i = 0;
	while (top != smaller && top != bigger \
		&& bottom != smaller && bottom != bigger)
	{
		top = top->next;
		bottom = bottom->prev;
		i++;
	}
	if (top == smaller)
		repeat_op(rotate, i, 'b', data);
	else if (top == bigger)
		repeat_op(rotate, i, 'b', data);
	else if (bottom == smaller)
		repeat_op(r_rotate, i + 1, 'b', data);
	else if (bottom == bigger)
		repeat_op(r_rotate, i + 1, 'b', data);
	push('a', data);
	if ((top == smaller) || ((bottom == smaller) && (top != bigger)))
		rotate('a', data);
}

void	minmax_sort(t_data	*data)
{
	int		i;

	i = 0;
	while (i < data->count)
	{
		if (data->stack_a->index <= data->count / 2)
			push('b', data);
		else
			rotate('a', data);
		i++;
	}
	while (data->stack_b)
		minmax(data, stack_bigger(data->stack_b), stack_smaller(data->stack_b));
	while (data->stack_a->index <= data->count / 2)
		rotate('a', data);
	while (data->stack_a->index > data->count / 2)
		push('b', data);
	while (data->stack_b)
		minmax(data, stack_bigger(data->stack_b), stack_smaller(data->stack_b));
	while (data->stack_a->index != 0)
		rotate('a', data);
}
