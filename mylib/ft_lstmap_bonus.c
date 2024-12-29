/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset < hbousset@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:43:23 by hbousset          #+#    #+#             */
/*   Updated: 2024/12/29 08:36:54 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			if (del)
				del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/* void	*duplicate_content(void *content)
{
	return (ft_strdup((char *)content));
}
void	del_content(void *content)
{
	free(content);
}

int main()
{
	t_list *lst = ft_lstnew(ft_strdup("ana"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("nta")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("sir")));

	t_list *new_lst = ft_lstmap(lst, duplicate_content, del_content);
	t_list *current = new_lst;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstclear(&lst, del_content);
	ft_lstclear(&new_lst, del_content);
} */
