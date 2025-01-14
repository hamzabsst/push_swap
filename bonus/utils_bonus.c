/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:51:27 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/14 22:44:16 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	*free_split(char **str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void	push(t_stack **dest, t_stack **src)
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

t_stack	**r_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !(*stack) || !((*stack)->next))
		return (NULL);
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack;
	second_last->next = NULL;
	*stack = last;
	return (stack);
}

t_stack	**rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return (NULL);
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	return (stack);
}

t_stack	**swap(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return (stack);
	first_node = *stack;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	if (first_node->next)
		first_node->next->prev = first_node;
	second_node->prev = first_node->prev;
	first_node->prev = second_node;
	*stack = second_node;
	return (stack);
}
