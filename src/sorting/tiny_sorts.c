/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:19:15 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/02 13:39:04 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	sa_ra(t_stack **a)
{
	sa(a);
	ra(a);
}

void	sort_3(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first < second && second < third)
		return;
	if (first > second && second < third && first > third)
		sa_ra(a);
	else if (first > second && second < third && first < third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		rra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
}

void	bubble_sort(int *values, int size)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (values[j] > values[j + 1])
			{
				temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	split_stack(t_stack **a, t_stack **b)
{
	int	median;
	int	size;

	if (!a || !(*a))
		return ;
	size = stack_len(*a);
	median = find_median(a);
	if (size <= 3)
		return;
	while (size > 3)
	{
		if ((*a)->value > median)
		{
			pb(b, a);
			size--;
		}
		else
			ra(a);
		median = find_median(a);
	}
	sort_3(a);
}
