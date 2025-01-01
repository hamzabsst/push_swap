/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:52:41 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/01 11:34:57 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	r_rotate(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack *before_last_node;

	first_node = *stack;
	if (stack == NULL || first_node == NULL || first_node->next == NULL)
		return ;
	last_node = is_last(first_node);
	before_last_node = last_node->prev;
	*stack = last_node;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	before_last_node->next = NULL;
}

void	rra(t_stack **a)
{
	r_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	r_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	r_rotate(a);
	r_rotate(b);
	ft_printf("rrr\n");
}
