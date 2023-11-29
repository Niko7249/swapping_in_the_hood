/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamiano <ntamiano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:04:47 by ntamiano          #+#    #+#             */
/*   Updated: 2023/11/29 17:42:38 by ntamiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <unistd.h> // read - write -
# include <stdlib.h> //write - free - exit


typedef struct s_stack_node
{
	int					value;
	int					current;
	int					final;
	int					push_weight;
	int					cheapest;
	int					flag1;
	int					flag2;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	int	prev;
}				t_stack_node;


// COMMANDS //
// PUSH
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **b, t_stack_node **a);
// ROTATE
void ra(t_stack_node **a);
void rb(t_stack_node **b);
void rr(t_stack_node **a, t_stack_node **b);
// REVERSE ROTATE
void rra(t_stack_node **a);
void rrb(t_stack_node **b);
void rrr(t_stack_node **a, t_stack_node **b);
// SWAP
void sa(t_stack_node **a);
void sb(t_stack_node **b);
void ss(t_stack_node **a, t_stack_node **b);


#endif
