/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:08:57 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/18 16:01:56 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	add = (t_ans *)ft_memalloc(sizeof(t_ans));
	add->cmd = ft_strdup(cmd);
	while(lst && lst->next)
		lst = lst->next;
	lst->next = add;
	return (lst);
}

int		lst_size(t_ans *lst)
{
	int	cpt;

	cpt = 0;
	lst = lst->next;
	while (lst)
	{
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
		return ;
	if (lst->next)
		delete_list(lst->next);
	ft_strdel(&lst->cmd);
	ft_memdel((void *)&lst);
}

