/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:52:38 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/01 15:21:43 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	push(t_stack **b, t_stack **a)
{
	t_stack	*pushed;

	if (!*a)
		return ;
	pushed = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	pushed->prev = NULL;
	if (!*b)
	{
		*b = pushed;
		pushed->next = NULL;
	}
	else
	{
		pushed->next = *b;
		pushed->next->prev = pushed;
		*b = pushed;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_printf("pb\n");
}
