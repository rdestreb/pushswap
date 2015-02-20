/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:08:57 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/20 19:45:46 by rdestreb         ###   ########.fr       */
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

t_ans	*add_link(t_ans *lst, char *cmd, t_stack *a, t_stack *b)
{
	t_ans	*add;
	t_ans	*tmp;
	int		*flag;

	flag = get_flag();
	add = (t_ans *)ft_memalloc(sizeof(t_ans));
	if (*flag & VERBOSE)
	{
		add->a = dup_stack(a);
		add->b = dup_stack(b);
	}
	add->cmd = ft_strdup(cmd);
	tmp = lst;
	if (tmp->last)
		tmp = tmp->last;
	tmp->next = add;
	lst->last = add;
	lst->cpt++;
	return (tmp);
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
	return (lst->cpt);
}

void	print_ans(t_ans	*lst)
{
	int	*flag;

	flag = get_flag();
	lst = lst->next;
	while (lst && lst->next)
	{
		if (*flag & VERBOSE)
		{
			ft_putendl(lst->cmd);
			print_stack(lst->a);
			print_stack(lst->b);
		}
		else
		{
			ft_putstr(lst->cmd);
			ft_putstr(" ");
		}
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

