/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:19:53 by hbousset          #+#    #+#             */
/*   Updated: 2024/11/10 12:15:15 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*  int main()
{
	t_list *node1 = ft_lstnew("hamza");
	t_list *node2 = ft_lstnew("is");
	t_list *node3 = ft_lstnew("him");
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	printf("%s", (char *)ft_lstlast(node1)->content);
} */
