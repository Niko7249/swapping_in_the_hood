/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamiano <ntamiano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:24:30 by ntamiano          #+#    #+#             */
/*   Updated: 2023/11/29 17:41:38 by ntamiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


void	free_matrix(char **argv)
{
	int	j;

	j = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[j])
		free(argv[j++]);
	free(argv - 1);
}

int	error_check_nb(char *str_nb)
{
	if (!(*str_nb == '+' || *str_nb == '-'
	|| (*str_nb >= '0' && *str_nb <= '9')))
		return (1);
	if ((*str_nb == '+' || *str_nb == '-')
	&& !(str_nb[1] >= '0' && str_nb[1] <= '9'))
		return (1);
	while (*++str_nb)
	{
		if (!(*str_nb >= '0' && *str_nb <= '9'))
			return (1);
	}
	return (0);
}



void free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*ongoing;

	if (stack == NULL)
		return ;
	ongoing = *stack;
	while (ongoing)
	{
		tmp = ongoing->next;
		free(ongoing);
		ongoing = tmp;
	}
	*stack = NULL;
}

void error_free(t_stack_node **a, char **argv, int flag_argc_2)
{
	free_stack(a);
	if (flag_argc_2)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}



int	error_rep(t_stack_node *a, 	int nb)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->value == nb)
			return (1);
		a = a->next;
	}
	return (0);
}
