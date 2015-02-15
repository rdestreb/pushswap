/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 12:21:12 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/15 15:41:24 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	sort_2(t_stack *stack)
{
	if (is_sorted(stack) == stack->size - 2)
		swap(stack);
}

void	rot_swap(t_stack *a)
{
	int pos;
	int	nb_rot;

	while (is_sorted(a) != -1)
	{
		pos = is_sorted(a);
//		printf("pos : %d\n", pos);
		printf("middle : %d\n", (a->size / 2));
		if (pos > ((a->size / 2) - 2))
		{
			nb_rot = (a->size - 1) - (pos + 1);
//			printf("nb_rot : %d\n", nb_rot);
			while (--nb_rot > -1)
				rotate(a);
			swap(a);
			while (++nb_rot < (a->size - 1) - (pos + 1))
				rev_rotate(a);
		}
		else
		{
			nb_rot = 2 + pos;
			while (--nb_rot > -1)
				rev_rotate(a);
			swap(a);
			while (++nb_rot < 2 + pos)
				rotate(a);
		}
	}
}
