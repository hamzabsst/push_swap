/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:59:31 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/31 09:11:03 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	errors(char *av)
{
	int	i;

	i = 0;
	if (!av[i])
		return (1);
	if (av[0] == '-' && av[1])
		i++;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
void	*free_errors(t_stack *a)
{
	t_node	*current;
	t_node	*temp;

	current = a->head;
	while (current)
	{
		temp = current->next;
		free (current);
		current = temp;
	}
	free (a);
	exit (1);
}
void	dub(t_stack *a, int value)
{
	t_node	*current;

	current = a->head;
	while (current)
	{
		if (current->value == value)
		{
			write(2, "Error\n", 6);
			free_errors(a);
		}
		current = current->next;
	}

}
