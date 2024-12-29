/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:19:41 by hbousset          #+#    #+#             */
/*   Updated: 2024/11/09 13:24:24 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/* int main()
{
	t_list *node1 = ft_lstnew("1");
	t_list *node2 = ft_lstnew("2");
	t_list *node3 = ft_lstnew("3");
	t_list *new = ft_lstnew("0");
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	ft_lstadd_front(&node1, new);
	t_list *current = node1;
	while (current)
	{
		printf("%s", (char *)current->content);
		current = current->next;
	}
} */
