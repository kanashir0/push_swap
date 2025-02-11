/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:13:55 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/02/11 10:16:59 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stack.c"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	// t_stack	*stack_b;
	char		**nums;

	stack_a = NULL;
	// stack_b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else if (argc == 2)
		nums = ft_split(argv[1], ' ');
	else
		nums = &argv[1];
	init_stack(stack_a, nums);
		
	return (0);
}