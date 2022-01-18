/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuter <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:26:39 by scuter            #+#    #+#             */
/*   Updated: 2022/01/18 10:24:16 by scuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_data
{
	int		count;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_data;

t_stack	*init_stack(int argc, char **argv);
void	free_stack(t_stack **stack);
void	error(t_stack **stack);
t_stack	*new_node(int num);
int		add_node(t_stack **stack, t_stack *new);
int		stack_len(t_stack *stack);
void	parse_indexes(t_data *data);

t_stack	*get_stack(char id, t_data *data);

t_stack	*stack_last(t_stack *stack);
t_stack	*stack_bigger(t_stack *stack);
t_stack	*stack_smaller(t_stack *stack);

void	put_on_top(t_stack *node, char id, t_data *data);
void	put_on_bottom(t_stack *node, char id, t_data *data);

int		is_sorted(t_stack *stack);

void	push(char id, t_data *data);
void	swap(char id, t_data *data);
void	rotate(char id, t_data *data);
void	r_rotate(char id, t_data *data);
void	repeat_op(void (*op)(char, t_data *), int i, char id, t_data *data);

void	sort_two(char id, t_data *data);
void	sort_three(char id, t_data *data);
void	insertion_sort(t_data *data);
void	minmax_sort(t_data	*data);
void	radix_sort(t_data *data);

#endif
