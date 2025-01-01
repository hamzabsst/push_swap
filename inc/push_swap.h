/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:13:54 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/01 10:27:19 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../mylib/myLib.h"
# include <stdbool.h>

typedef struct s_stack
{
	int					value;
	int					index;
	int					cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack		*pivot;
	struct s_stack		*next;
	struct s_stack		*prev;
}						t_stack;

// create stack a
void	init_stack(t_stack **a, char **av);
// create node
void	add_node(t_stack **stack, int value);
t_stack	*create_node(int value);

// handle errors
int		check_errors(char *av);
int		check_duplicate(t_stack *a, int value);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **a);

// stack utils
int		stack_len(t_stack *stack);
t_stack	*is_last(t_stack *head);

//test
void	print(t_stack *stack);

#endif
