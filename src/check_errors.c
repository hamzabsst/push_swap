/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:59:31 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/15 13:25:54 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_errors(char *av)
{
	int	i;

	i = 0;
	if (!av[i])
		return (1);
	if (!(av[i] == '+' || av[i] == '-'
			|| (av[i] >= '0' && av[i] <= '9')))
		return (1);
	if ((av[i] == '+' || av[i] == '-')
		&& !(av[i + 1] >= '0' && av[i + 1] <= '9'))
		return (1);
	i++;
	while (av[i])
	{
		if (!(av[i] >= '0' && av[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	check_duplicate(t_stack *a, int value)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == value)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		current->value = 0;
		free (current);
		current = temp;
	}
	*stack = NULL;
}

void	free_errors(t_stack **stack)
{
	if (stack)
		free_stack(stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

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
