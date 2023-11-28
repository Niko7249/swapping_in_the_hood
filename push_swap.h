/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamiano <ntamiano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:04:47 by ntamiano          #+#    #+#             */
/*   Updated: 2023/11/27 16:42:56 by ntamiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <unistd.h> // read - write -
# include <stdlib.h> //write - free - exit

# define INT_MAX = 2147483647
# define INT_MIN = -2147483648

typedef struct s_stack_node
{
	int	a;
	int	b;
	int	c;
	long	value;
	int	next;
	int	prev;
}				t_stack_node;


#endif
