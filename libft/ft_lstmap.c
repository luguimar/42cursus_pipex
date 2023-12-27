/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:26:57 by luguimar          #+#    #+#             */
/*   Updated: 2023/05/12 17:13:29 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	new_node = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
/*
#include <stdio.h>

void	*ft_lsttoupper(void *content)
{
	int	i;
	char	*str;
	char	*new_str;

	str = (char *) content;
	new_str = ft_strdup(str);
	if (!new_str)
		return (NULL);
	i = 0;
	while (new_str[i] != '\0')
	{
		new_str[i] = ft_toupper(str[i]);
		i++;
	}
	return (new_str);
}

void	delcontent(void *content)
{
	free(content);
	content = NULL;
}

int	main(void)
{
	t_list	*lista;
	t_list	*lista1;
	t_list	*lista2;
	t_list	*lista3;
	t_list	*templist;
	t_list	*listanova;
	char	*str;
	char	*str1;
	char	*str2;
	char	*str3;
	int	i;

	str = malloc(sizeof(char) * 9);
	str1 = malloc(sizeof(char) * 7);
	str2 = malloc(sizeof(char) * 7);
	str3 = malloc(sizeof(char) * 7);
	i = 0;
	while (i < 8)
	{
		str[i] = 'a' + (char) i;
		i++;
	}
	str[i] = '\0';
	i = 0;
	while (i < 6)
	{
		str1[i] = 'i' + (char) i;
		i++;
	}
	str1[i] = '\0';
	i = 0;
	while (i < 6)
	{
		str2[i] = 'o' + (char) i;
		i++;
	}
	str2[i] = '\0';
	i = 0;
	while (i < 6)
	{
		str3[i] = 'u' + (char) i;
		i++;
	}
	str3[i] = '\0';
	lista = ft_lstnew(str);
	lista1 = ft_lstnew(str1);
	lista2 = ft_lstnew(str2);
	lista3 = ft_lstnew(str3);
	ft_lstadd_back(&lista, lista1);
	ft_lstadd_back(&lista, lista2);
	ft_lstadd_back(&lista, lista3);
	listanova = ft_lstmap(lista, ft_lsttoupper, delcontent);
	templist = listanova;
	while (templist)
	{
		printf("%s\n", (char *)templist->content);
		templist = templist->next;
	}
	ft_lstclear(&listanova, delcontent);
	ft_lstclear(&lista, delcontent);
	return (0);
}*/
