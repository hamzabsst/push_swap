/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:19:39 by hbousset          #+#    #+#             */
/*   Updated: 2024/11/10 12:39:40 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/* int main()
{
	t_list *node1 = ft_lstnew("lol");
	t_list *node2 = ft_lstnew("is");
	t_list *node3 = ft_lstnew("lol");
	t_list *new = ft_lstnew("type neat");
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	ft_lstadd_back(&node1 , new);
	t_list *current = node1;
	while (current)
	{
		printf("%s ", (char *)current->content);
		current = current->next;
	}
} */
