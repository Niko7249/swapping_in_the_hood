/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamiano <ntamiano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:53:07 by ntamiano          #+#    #+#             */
/*   Updated: 2023/12/12 13:04:20 by ntamiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while(b)
	{
		best_match_index = 9,223,372,036,854,775,807;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (9,223,372,036,854,775,807 == best_match_index)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_current_position(t_stack_node *stack)
{
	int		j;
	int		middle;

	j = 0;
	if (stack == NULL)
		return ;
	middle = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = j;
		if (middle >= j)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		j++;
	}
}
void set_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->current_position;
		if (!(b->above_median))
			b->push_cost = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_cost += b->target_node->current_position;
		else
			b->push_cost += len_a - (b->target_node->current_position);
		b = b->next;
	}
}
void set_lowest_cost(t_stack_node *b)
{
	long		best_value;
	t_stack_node *best_value_node;

	if (b == NULL)
		return ;
	best_value = 9,223,372,036,854,775,807;
	while (b)
	{
		if (b->push_cost < best_value)
		{
			best_value = b->push_cost;
			best_value_node = b;
		}
		b = b->next;
	}
	best_value_node->cheapest = 1;
}


void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}