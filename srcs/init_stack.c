/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:43:31 by scuter            #+#    #+#             */
/*   Updated: 2022/01/18 11:23:24 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	valid_int(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

static t_stack	*parse_stack(char **argv)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	while (*argv)
	{
		i = 0;
		if (!valid_int(ft_atoi(*argv)))
			error(&stack);
		while (argv[0][i])
		{
			if ((!ft_isdigit(argv[0][i]) && argv[0][i] != '-') \
				|| (argv[0][i] == '-' && i > 0) \
				|| (argv[0][0] == 0 && !ft_isdigit(argv[0][1])))
				error(&stack);
			i++;
		}
		if (!add_node(&stack, new_node(ft_atoi(*argv))))
			error(&stack);
		argv += 1;
	}
	return (stack);
}

static void	free_table(char ***table)
{
	char	**ptr;

	ptr = *table;
	while (**table != NULL)
	{
		free(**table);
		*table += 1;
	}
	free(ptr);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack;
	char	**split_argv;

	if (argc == 2)
	{
		split_argv = ft_split(*argv, ' ');
		stack = parse_stack(split_argv);
		free_table(&split_argv);
		return (stack);
	}
	return (parse_stack(argv));
}
