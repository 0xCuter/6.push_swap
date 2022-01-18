/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:35:21 by scuter            #+#    #+#             */
/*   Updated: 2022/01/17 13:36:01 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_bigger(t_stack *stack)
{
	t_stack	*bigger;

	bigger = stack;
	while (stack)
	{
		if (stack->num > bigger->num)
			bigger = stack;
		stack = stack->next;
	}
	return (bigger);
}

t_stack	*stack_smaller(t_stack *stack)
{
	t_stack	*smaller;

	smaller = stack;
	while (stack)
	{
		if (stack->num < smaller->num)
			smaller = stack;
		stack = stack->next;
	}
	return (smaller);
}
