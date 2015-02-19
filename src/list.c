/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:08:57 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/19 15:52:29 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_ans	*singleton(void)
{
	static t_ans	*lst = NULL;

	if (!lst)
		lst = (t_ans *)ft_memalloc(sizeof(t_ans));
	return (lst);
}

t_ans	*add_link(t_ans *lst, char *cmd)
{
	t_ans	*add;
	t_ans	*tmp;

	add = (t_ans *)ft_memalloc(sizeof(t_ans));
	add->cmd = ft_strdup(cmd);
	tmp = lst;
	if (tmp->last)
		tmp = tmp->last;
	tmp->next = add;
	lst->last = add;
	return (tmp);
}

int		lst_size(t_ans *lst)
{
	int	cpt;

	cpt = 0;
	lst = lst->next;
	while (lst)
	{
		//printf("lst_size\n");
		cpt++;
		lst = lst->next;
	}
	return (cpt);
}

void	print_ans(t_ans	*lst)
{
	lst = lst->next;
	while(lst && lst->next)
	{
		printf("print_ans\n");
		ft_putstr(lst->cmd);
		ft_putstr(" ");
		lst = lst->next;
	}
	if (lst)
		ft_putendl(lst->cmd);
}

void	delete_list(t_ans *lst)
{
	if (!lst)
	{
		return ;
	}
	//printf("delete: %s ", lst->cmd);
	if (lst->next)
		delete_list(lst->next);
	else
		printf("%s\n", "done");

	//ft_strdel(&lst->cmd);
	//ft_memdel((void *)&lst);
}

