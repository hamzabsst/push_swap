/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:52:38 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/04 11:41:23 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*pushed;

	if (!*src)
		return ;
	pushed = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	pushed->prev = NULL;
	if (!*dest)
	{
		*dest = pushed;
		pushed->next = NULL;
	}
	else
	{
		pushed->next = *dest;
		pushed->next->prev = pushed;
		*dest = pushed;
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
