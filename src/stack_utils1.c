/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:36:25 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/04 13:42:16 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_second_min(t_stack *stack)
{
	int		min;
	int		second_min;

	if (!stack)
		return (0);
	min = find_min(stack);
	second_min = INT_MAX;
	while (stack)
	{
		if (stack->value != min && stack->value < second_min)
			second_min = stack->value;
		stack = stack->next;
	}
	return (second_min);
}
