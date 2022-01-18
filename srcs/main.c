/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:33:56 by scuter            #+#    #+#             */
/*   Updated: 2022/01/18 10:45:11 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.stack_a = init_stack(argc, argv + 1);
	data.stack_b = NULL;
	data.count = stack_len(data.stack_a);
	if (data.count < 2)
	{
		free_stack(&data.stack_a);
		return (0);
	}
	parse_indexes(&data);
	if (data.count == 2)
		sort_two('a', &data);
	else if (data.count == 3)
		sort_three('a', &data);
	else if (data.count <= 20)
		insertion_sort(&data);
	else if (data.count <= 200)
		minmax_sort(&data);
	else
		radix_sort(&data);
	free_stack(&data.stack_a);
	return (0);
}
