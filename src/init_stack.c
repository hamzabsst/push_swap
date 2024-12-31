/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:00:06 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/31 09:10:47 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stack(t_stack **a, char **av)
{
	long	value;
	int		i;

	i = 0;
	while (av[i])
	{
		if (errors(av[i]))
		{
			free_errors(*a);
			write(2, "Error\n", 6);
		}
		value = ft_atol(av[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			free_errors(*a);
			write(2, "Error\n", 6);
		}
		dub(*a, (int)value);
		add(a, (int)value);
		i++;
	}
}

void	add(t_stack **a, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		free_errors(*a);
	new_node->value = value;
	new_node->next = (*a)->head;
	new_node->previous = NULL;

	if ((*a)->head)
		(*a)->head->previous = new_node;
	(*a)->head = new_node;
	(*a)->size++;
}
