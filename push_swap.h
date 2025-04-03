/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:30:31 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/04/02 21:18:51 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack_node {
	int				value;
	t_stack_node	*next;
	t_stack_node	*prev;
}					t_stack_node;


// STACK
void	stack_init(t_stack_node **a, char **argv, int flag_argc_2);
t_stack_node	*get_last_node(t_stack_node *stack);

#endif