/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 18:14:14 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/11 16:22:08 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rotate(t_stack *st)
{
	int	i;
	int	tmp;

	tmp = st->stack[st->size - 1];
	i = st->size;
	while (--i > 0)
		st->stack[i] = st->stack[i - 1];
	st->stack[i] = tmp;
	ft_putendl(ft_strjoin("r", st->name));
	return (st);
}

t_stack	*rev_rotate(t_stack *st)
{
	int	i;
	int	tmp;

	tmp = st->stack[0];
	i = -1;
	while (++i < st->size - 1)
		st->stack[i] = st->stack[i + 1];
	st->stack[i] = tmp;
	ft_putendl(ft_strjoin("rr", st->name));
	return (st);
}
