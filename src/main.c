/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:52:38 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/31 09:29:55 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	*free_split(char **str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free (str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	**args;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		return (1);
	a->head = NULL;
	b->head = NULL;
	a->size = 0;
	b->size = 0;
	i = 0;
	if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
		return (1);
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		while (args[i])
			i++;
	}
	else
		args = av + 1;
	init_stack(&a, args);
	if (ac == 2)
		free_split(args, i);
	print_stack(a);
	free_errors(a);
	free_errors(b);
}
void print_stack(t_stack *stack)
{
	t_node *current;

	current = stack->head;
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
	ft_printf("\n");
}
