/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:48:29 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/30 08:43:46 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	current = stack->top;
	while (current)
	{
		next_node = current->next;
		free (current);
		current = next_node;
	}
	free (stack);
}
/* int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	current = stack->top;
	min = current->value;

	if (is_empty(stack))
		return (-1);
	while (current)
	{
		if (current->value < min)
			min = current->next;
		current = current->next;
	}
	return (min);
}
void	sort_stack(t_stack *a, t_stack *b)
{
	int	min;
	int	value;

	if (!is_empty(a))
	{
		min = find_min(a);
		while (a->top->value != min)
		{
			ra(a);
			ft_printf("a");
		}



	}
} */
