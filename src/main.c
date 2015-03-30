/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:56:18 by rdestreb          #+#    #+#             */
/*   Updated: 2015/03/30 14:46:07 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *msg)
{
	ft_putstr_fd("Push_Swap : Error : ", 2);
	ft_putstr_fd(msg, 2);
	exit(2);
}

void	comp_algo(t_stack *a, t_stack *b, int ac, char **av)
{
	t_ans	*ans1;
	t_ans	*ans2;
	int		tmp;
	int		*flag;

	flag = get_flag();
	if (is_sorted(a) == -1)
		return ;
	ans1 = (t_ans *)ft_memalloc(sizeof(t_ans));
	ans2 = (t_ans *)ft_memalloc(sizeof(t_ans));
	tmp = a->size;
	if (*flag & R_S && !(*flag & INS))
		rot_swap(a, b, ans1);
	else if (*flag & INS && !(*flag & R_S))
		push_min(a, b, ans2);
	else
	{
		rot_swap(a, b, ans1);
		ft_memdel((void *)&a);
		a = create_stack(av, ac, tmp, 'a');
		push_min(a, b, ans2);
	}
	display(ans1, ans2, a, b);
}

int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		nb_opt;
	int		*flag;

	nb_opt = init_flags(ac, av);
	is_valid(av, ac, nb_opt);
	a = create_stack(av, ac, ac - 1 - nb_opt, 'a');
	b = create_stack(av, ac, ac - 1 - nb_opt, 'b');
	b->size = 0;
	is_duplicate(a);
	flag = get_flag();
	if (*flag & VERBOSE)
	{
		print_stack(a);
		print_stack(b);
	}
	comp_algo(a, b, ac, av);
	return (0);
}
