/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:30:03 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/02/11 10:28:19 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int	init_stack(t_stack *a, char **args)
{
	t_stack	*stack;

	stack = NULL;
	stack = (t_stack *)malloc(sizeof(t_stack));
	return (stack);
}

int	is_stack_sorted(t_stack *a)
{
	if (a == NULL)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
// t_stack	*insert_to_stack(t_stack *stack, int i)
// {

// }

void ola()
{
	printf("ola\n");
}