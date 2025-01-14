/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:13:54 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/14 11:20:58 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../mylib/myLib.h"

typedef struct s_stack
{
	int				value;
	int				cost;
	int				above_mid;
	int				rank;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}					t_stack;

// handle errors
int		check_errors(char *av);
int		check_duplicate(t_stack *a, int value);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **a);

// create stack
int		init_stack(t_stack **a, char **av);
void	add_node(t_stack **stack, int value);
t_stack	*create_node(int value);
t_stack	*is_last(t_stack *stack);

// stack utils
int		is_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
void	ranking(t_stack *stack);
t_stack	*find_min(t_stack *a);
t_stack	*is_cheapest(t_stack *b);

// stack utils 2
void	is_above_mid(t_stack *stack);
void	find_target(t_stack *a, t_stack *b);
t_stack	*calculate_cost(t_stack *a, t_stack *b);

//tiny sorting
void	sort_3(t_stack **a);
void	sort_5(t_stack **a, t_stack **b);
int		find_min_value(t_stack *stack);
int		find_second_min(t_stack *stack);

//sort_stack
void	sort_stack(t_stack **a, t_stack **b);
void	push_swap(t_stack **a, t_stack **b);
void	push_a_to_b(t_stack **a, t_stack **b);
void	push_b_to_a(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rotation(t_stack **stack, t_stack *cheapest, char stack_name);

// commands
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
