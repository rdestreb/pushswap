/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 17:57:43 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/11 14:06:49 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack *st)
{
	int	tmp;

	tmp = st->stack[st->size - 1];
	st->stack[st->size - 1] = st->stack[st->size - 2];
	st->stack[st->size - 2] = tmp;
	ft_putendl(ft_strjoin("s", st->name));
	return (st);
}
