/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_indexes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:43:09 by scuter            #+#    #+#             */
/*   Updated: 2022/01/17 13:49:39 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	fill_list(int *list, t_stack *stack)
{
	t_stack	*current;
	int		i;

	current = stack;
	i = 0;
	while (current)
	{
		list[i] = current->num;
		i++;
		current = current->next;
	}
}

static void	sort_list(int *list, int len)
{
	int	i;
	int	j;
	int	shorter;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		shorter = i;
		j = i + 1;
		while (j < len)
		{
			if (list[j] < list[shorter])
				shorter = j;
			j++;
		}
		if (shorter != i)
		{
			tmp = list[i];
			list[i] = list[shorter];
			list[shorter] = tmp;
		}
		i++;
	}
}

static void	get_indexes(int *list, t_data *data)
{
	t_stack	*current;
	int		i;

	current = data->stack_a;
	while (current)
	{
		i = 0;
		while (i < data->count)
		{
			if (list[i] == current->num)
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	parse_indexes(t_data *data)
{
	int		*list;

	list = malloc(sizeof(int) * data->count);
	if (!list)
		error(&data->stack_a);
	fill_list(list, data->stack_a);
	sort_list(list, data->count);
	get_indexes(list, data);
	free(list);
}
