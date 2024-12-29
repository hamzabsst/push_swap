/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:19:47 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/29 08:36:54 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/* void del(void *content)
{
	free(content);
}
int main()
{
	t_list *head = ft_lstnew(ft_strdup("1"));
	t_list *second = ft_lstnew(ft_strdup("2"));
	t_list *third = ft_lstnew(ft_strdup("3"));
	head->next = second;
	second->next = third;

	head->next = third;
	ft_lstdelone(second, del);

	t_list *current = head;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstdelone(head, del);
	ft_lstdelone(third, del);
} */
