/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamiano <ntamiano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:04:47 by ntamiano          #+#    #+#             */
/*   Updated: 2023/12/12 14:00:17 by ntamiano         ###   ########.fr       */
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
	int					above_median;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

// SPLIT.C
char			**ft_split(char *str, char separator);

// UTILS_ERROR.C
void			free_matrix(char **argv);
void			free_stack(t_stack_node **stack);
void			error_free(t_stack_node **a, char **argv, int flag_argc_2);
int				error_check_nb(char *str_nb);
int				error_rep(t_stack_node *a, 	int nb);

// INIT.C
void			stack_init(t_stack_node **a, char **argv, int flag_argc_2);

// UTILS_INIT.C
void			append_node(t_stack_node **stack, int nb);
t_stack_node	*find_last_node(t_stack_node *head);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
int				stack_len(t_stack_node *stack);

//sort_3_nb.C
int	stack_sorted(t_stack_node *stack);
void	three_nb_sort(t_stack_node **a);
void five_nb_sort(t_stack_node **a, t_stack_node **b);

//sort5_nb.C
void	set_current_position(t_stack_node *stack);
void set_cost(t_stack_node *a, t_stack_node *b);
void set_lowest_cost(t_stack_node *b);
void	init_nodes(t_stack_node *a, t_stack_node *b);

//sort_push_swap.c
void finish_rotation(t_stack_node **stack, t_stack_node *top_node, char stack_name);
void push_swap (t_stack_node **a, t_stack_node **b);

// MAIN.C


// COMMANDS //
// PUSH
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **b, t_stack_node **a);
// ROTATE
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);
// REVERSE ROTATE
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b);
// SWAP
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);


#endif
