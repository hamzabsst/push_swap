/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:13:54 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/31 09:05:53 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../mylib/myLib.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

void	init_stack(t_stack **a, char **av);
void	add(t_stack **a, int value);
int		errors(char *av);
void	*free_errors(t_stack *a);
void	dub(t_stack *a, int value);
void	print_stack(t_stack *stack);

#endif
