/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 08:33:21 by scuter            #+#    #+#             */
/*   Updated: 2022/01/17 13:50:10 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_on_top(t_stack *node, char id, t_data *data)
{
	t_stack	*stack;
	int		i;
	int		len;

	stack = get_stack(id, data);
	i = 0;
	len = stack_len(stack);
	while (stack)
	{
		if (node == stack)
		{
			if (i < len / 2)
				repeat_op(rotate, i, id, data);
			else
				repeat_op(r_rotate, len - i, id, data);
		}
		i++;
		stack = stack->next;
	}
}

void	put_on_bottom(t_stack *node, char id, t_data *data)
{
	t_stack	*stack;
	int		i;
	int		len;

	stack = get_stack(id, data);
	i = 0;
	len = stack_len(stack);
	while (stack)
	{
		if (node == stack)
		{
			if (i < len / 2)
				repeat_op(rotate, i + 1, id, data);
			else
				repeat_op(r_rotate, len - i - 1, id, data);
		}
		i++;
		stack = stack->next;
	}
}
