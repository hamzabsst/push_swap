/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:52:38 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/05 10:40:10 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	*free_split(char **str)
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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**arv;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		arv = ft_split(av[1], 32);
	else
		arv = av + 1;
	init_stack(&a, arv);
	if (ac == 2)
		free_split(arv);
	if (!is_sorted(a))
		sort_stack(&a, &b);
	ft_printf("%s\n", "stack a is");
	print(a);
	ft_printf("%s\n", "stack b is");
	print(b);
	free_stack(&a);
	free_stack(&b);
}

void	print(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}
