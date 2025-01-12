/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:28:05 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/12 13:22:44 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	if (!a || !(*a))
		return ;
	if (stack_len(*a) == 2)
		sa(a);
	else if (stack_len(*a) == 3)
		sort_3(a);
	else if (stack_len(*a) == 4)
		sort_4(a, b);
	else if (stack_len(*a) == 5)
		sort_5(a, b);
	else
		push_swap(a, b);
}
void push_swap(t_stack **a, t_stack **b)
{
	indexing(*a);
	split_to_b(a, b);
	sort_3(a);
	push_back_to_a(a, b);
}
