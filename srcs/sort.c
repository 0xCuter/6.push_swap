/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 08:27:25 by scuter            #+#    #+#             */
/*   Updated: 2022/01/18 10:28:54 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(char id, t_data *data)
{
	t_stack	*stack;

	stack = get_stack(id, data);
	if (stack->num > stack->next->num)
		swap(id, data);
}

void	sort_three(char id, t_data *data)
{
	t_stack	*stack;

	stack = get_stack(id, data);
	put_on_bottom(stack_bigger(stack), id, data);
	sort_two(id, data);
}

void	insertion_sort(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count - 3)
	{
		if (is_sorted(data->stack_a))
			break ;
		put_on_top(stack_smaller(data->stack_a), 'a', data);
		push('b', data);
		i++;
	}
	sort_three('a', data);
	while (i > 0)
	{
		push('a', data);
		i--;
	}
}

static void	radix_split(int index, int bit, t_data *data)
{
	if ((index & bit) == bit)
		rotate('a', data);
	else
		push('b', data);
}

void	radix_sort(t_data *data)
{
	t_stack	*current;
	int		index;
	int		i;
	int		bit;

	bit = 1;
	while (!is_sorted(data->stack_a))
	{
		current = data->stack_a;
		i = 0;
		while (i < data->count)
		{
			index = current->index;
			current = current->next;
			radix_split(index, bit, data);
			i++;
		}
		current = data->stack_b;
		while (current != NULL)
		{
			current = current->next;
			push('a', data);
		}
		bit = bit << 1;
	}
}
