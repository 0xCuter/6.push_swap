/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:05:12 by scuter            #+#    #+#             */
/*   Updated: 2022/01/17 13:51:33 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

void	error(t_stack **stack)
{
	write(2, "Error\n", 6);
	free_stack(stack);
	exit(1);
}

void	repeat_op(void (*op)(char, t_data *), int i, char id, t_data *data)
{
	while (i--)
	{
		op(id, data);
	}
}
