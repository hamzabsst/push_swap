/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:29:31 by hbousset          #+#    #+#             */
/*   Updated: 2025/01/14 22:31:50 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../inc/push_swap.h"
# include "../mylib/myLib.h"

void	do_command(t_stack **a, t_stack **b, char *line);
void	checker(t_stack **a, t_stack **b);

// utils
void	*free_split(char **str);
void	push(t_stack **dest, t_stack **src);
t_stack	**r_rotate(t_stack **stack);
t_stack	**rotate(t_stack **stack);
t_stack	**swap(t_stack **stack);

// utils1
int		cleanup(t_stack **a, t_stack **b);
int		handle_args(char **av, int ac, char ***arv, int *split_flag);
char	*join_args(char **av, int ac);
int		cleanup_and_exit(t_stack **a, t_stack **b, char **arv, int flag);

#endif
