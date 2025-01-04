/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:19:15 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/04 14:35:56 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_3(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	while (!is_sorted(*a))
	{
		first = (*a)->value;
		second = (*a)->next->value;
		third = (*a)->next->next->value;
		if (first > second && first > third)
			ra(a);
		else if (second > first && second > third)
			rra(a);
		else if (first > second)
			sa(a);
	}
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	pushed;

	pushed = 0;
	while (stack_len(*a) > 3 && pushed < 2)
	{
		if ((*a)->value == find_min(*a) || (*a)->value == find_second_min(*a))
		{
			pb(b, a);
			pushed++;
		}
		else
			ra(a);
	}
	if (stack_len(*a) == 3)
		sort_3(a);
	if (stack_len(*b) == 2 && (*b)->value < (*b)->next->value)
		sb(b);
	pa(a ,b);
	pa(a ,b);
}
