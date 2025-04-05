/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:30:31 by gyasuhir          #+#    #+#             */
/*   Updated: 2025/04/05 00:35:57 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// Handle errors
bool			error_syntax(char *n);
bool			error_duplicate(t_stack_node *a, int n);
void			error_free(t_stack_node **a, char **argv, bool flag_argc_2);
void			free_stack(t_stack_node **stack);
void			free_matrix(char **argv);

// Stack initialization
void			append_node(t_stack_node **stack, int nbr);
void			stack_init(t_stack_node **a, char **argv, int flag_argc_2);

// Nodes initialization
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);

// Stack utils
t_stack_node	*get_last_node(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
void			min_to_top(t_stack_node **a);

// Commands
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **b, t_stack_node **a);
void			pb(t_stack_node **a, t_stack_node **b);
void			rotate_both(t_stack_node **a,
					t_stack_node **b, t_stack_node *cheapest_node);
void			rev_rotate_both(t_stack_node **a,
					t_stack_node **b, t_stack_node *cheapest_node);

// Algorithm
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

#endif