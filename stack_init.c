/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:30:03 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/04/05 00:27:01 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	stack_init(t_stack_node **a, char **argv, int flag_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_argc_2);
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_duplicate(*a, (int)nbr))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)nbr);
		i++;
	}
	if (flag_argc_2)
		free_matrix(argv);
	return ;
}

void	min_to_top(t_stack_node **a)
{
	t_stack_node	*min_node;

	min_node = find_min(*a);
	while ((*a)->value != min_node->value)
	{
		if (min_node->above_median)
			ra(a);
		else
			rra(a);
	}
}
