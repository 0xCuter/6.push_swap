/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:21:29 by scuter            #+#    #+#             */
/*   Updated: 2022/01/18 10:30:03 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node(int num)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->num = num;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	add_node(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if (!*stack)
	{
		*stack = new;
		return (1);
	}
	current = *stack;
	while (1)
	{
		if (current->num == new->num)
			return (0);
		if (!current->next)
			break ;
		current = current->next;
	}
	current->next = new;
	new->prev = current;
	return (1);
}

int	stack_len(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stack	*get_stack(char id, t_data *data)
{
	if (id == 'a')
		return (data->stack_a);
	else if (id == 'b')
		return (data->stack_b);
	return (NULL);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
