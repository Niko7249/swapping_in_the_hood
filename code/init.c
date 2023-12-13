/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamiano <ntamiano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:25:17 by ntamiano          #+#    #+#             */
/*   Updated: 2023/12/13 14:44:16 by ntamiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	nb;
	int		isneg;
	int		j;

	nb = 0;
	isneg = 1;
	j = 0;
	while (str[j] && (str[j] == ' ' || str[j] == '\t'
			|| str[j] == '\n' || str[j] == '\r'
			|| str[j] == '\v' || str[j] == '\f'))
		j++;
	if (str[j] == '+')
		j++;
	else if (str[j] == '-')
	{
		isneg *= -1;
		j++;
	}
	while (str[j] >= '0' && str[j] <= '9')
	{
		nb = (nb * 10) + (str[j] - '0');
		j++;
	}
	return (nb * isneg);
}

void	stack_init(t_stack_node **a, char **argv, int flag_argc_2)
{
	long	nb;
	int		j;

	j = 0;
	while (argv[j])
	{
		if (error_check_nb(argv[j]))
			error_free(a, argv, flag_argc_2);
		nb = ft_atol(argv[j]);
		if ((nb > 2147483647) || (nb < -2147483648))
			error_free(a, argv, flag_argc_2);
		if (error_rep(*a, (int)nb))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)nb);
		j++;
	}
	if (flag_argc_2)
		free_matrix(argv);
}
