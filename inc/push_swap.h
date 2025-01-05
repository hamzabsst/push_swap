/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:13:54 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/05 10:56:56 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../mylib/myLib.h"
# include <stdbool.h>

typedef struct s_stack
{
	int					value;
	struct s_stack		*next;
	struct s_stack		*prev;
}						t_stack;

// create stack
void	init_stack(t_stack **a, char **av);
void	add_node(t_stack **stack, int value);
t_stack	*create_node(int value);

// handle errors
int		check_errors(char *av);
int		check_duplicate(t_stack *a, int value);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **a);

// stack utils
t_stack	*is_last(t_stack *head);
int		find_max(t_stack *stack);
int		stack_len(t_stack *stack);
int		find_min(t_stack *stack);
int		find_second_min(t_stack *stack);

// stack utils 2
int		is_sorted(t_stack *a);
void	indexing(t_stack *stack);

//sorts
void	sort_3(t_stack **a);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);

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

//test
void	print(t_stack *stack);

#endif
