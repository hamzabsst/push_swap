/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:28:05 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/04 09:23:20 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	split_stack(a, b);
	if (stack_len(*a) == 3)
		sort_3(a);
	else if (stack_len(*a) == 2)
		sa(a);
}
