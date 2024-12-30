/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:13:54 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/29 15:24:37 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../mylib/myLib.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}				t_node;
typedef struct s_stack
{
	t_node	*top;
	int		size;
}				t_stack;

t_stack	*create_stack(void);
void	push(t_stack *stack, int value);
void	free_stack(t_stack *stack);
void	print_stack(t_stack *stack);

#endif
