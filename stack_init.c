/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:30:03 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/04/02 18:03:15 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_free(t_stack_node **a, char **argv, int flag_argc_2)
{
	(void)a;
	(void)argv;
	(void)flag_argc_2;
	return ;
}

int	error_syntax(char *n)
{
	(void)n;
	return (0);
}

void	stack_init(t_stack_node **a, char **argv, int flag_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i])) //TODO error_syntax()
			error_free(a, argv, flag_argc_2); // TODO error_free()
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)nbr);
		i++;
	}
	if (flag_argc_2)
		free_matrix(argv); // TODO free_matrix()
	return (1);
}
