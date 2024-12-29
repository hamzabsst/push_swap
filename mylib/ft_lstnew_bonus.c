/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:19:23 by hbousset          #+#    #+#             */
/*   Updated: 2024/11/09 12:48:40 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myLib.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->content = content;
	return (new_node);
}
/* int main ()
{
	char *str = "hamza";
	t_list *new = ft_lstnew(str);
	printf("%s", (char *)new->content);
}
 */
