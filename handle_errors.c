/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:08:55 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/04/03 20:40:38 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	error_syntax(char *n)
{
	if (!(*n == '+' || *n == '-' || (*n >= '0' && *n <= '9')))
		return (true);
	if ((*n == '+' || *n == '-') && !(n[1] >= '0' && n[1] <= '9'))
		return (true);
	while (*++n)
	{
		if (!(*n >= '0' && *n <= '9'))
			return (true);
	}
	return (false);
}

bool	error_duplicate(t_stack_node *a, int n)
{
	if (a == NULL)
		return (false);
	while (a)
	{
		if (a->value == n)
			return (true);
		a = a->next;
	}
	return (false);
}

void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack_node **a, char **argv, bool flag_argc_2)
{
	free_stack(a);
	if (flag_argc_2)
		free_matrix(argv);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}