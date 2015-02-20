/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:56:18 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/20 16:24:51 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
#include <stdio.h>
void	print_error(char *msg)
{
	ft_putstr_fd("Push_Swap : Error : ", 2);
	ft_putstr_fd(msg, 2);
	exit(2);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = -1;
	while (++i < a->size - 1)
	{
		if (a->stack[i] < a->stack[i + 1])
			return (i + 1);
	}
	return (-1);
}

int	rev_is_sorted(t_stack *a)
{
	int	i;

	i = a->size;
	while (--i > 0)
	{
		if (a->stack[i] > a->stack[i - 1])
			return (i - 1);
	}
	return (-1);
}

void	is_valid(char **av, int ac, int nb_opt)
{
	int	i;
	int arg;

	if (ac < 3 + nb_opt)
		print_error("Please enter at least 2 digits, without duplicates\n");
	arg = nb_opt;
	while (++arg < ac)
	{
		if (ft_strcmp(ft_itoa(ft_atoi(av[arg])), av[arg]))
			print_error("At least one argument is INT over-limited\n");
		i = -1;
		if (av[arg][0] == '-' && ft_isdigit(av[arg][1]))
			i = 0;
		while (av[arg][++i])
		{
			if (!(ft_isdigit(av[arg][i])))
				print_error("At least one argument is not an INT digit\n");
		}
	}
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
	rot_swap(a, ans1);
	ft_memdel((void *)&a);
	a = create_stack(av, ac, tmp, 'a');
	push_min(a, b, ans2);
	print_ans(ans1);
	print_ans(ans2);
//	(ans1->cpt > ans2->cpt) ? print_ans(ans2) : print_ans(ans1);
//	ft_putnbr(ans2->cpt);
	if (*flag & VERBOSE)
		ft_putendl("verbose");
	if (*flag & NB_OP)
	{
		(ans1->cpt > ans2->cpt) ? ft_putnbr(ans2->cpt) : ft_putnbr(ans1->cpt);
		ft_putendl("");
	}
	if (*flag & BEST_ALGO)
	{
		(ans1->cpt > ans2->cpt) ? ft_putendl("'Insertion'")
			: ft_putendl("'Push-Swap'");
	}
	ft_memdel((void *)&a);
	ft_memdel((void *)&b);
//	delete_list(ans1);
//	delete_list(ans2);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		nb_opt;

	nb_opt = init_flags(ac, av);
	is_valid(av, ac, nb_opt);
	a = create_stack(av, ac, ac - 1 - nb_opt, 'a');
	b = create_stack(av, ac, ac - 1 - nb_opt, 'b');
	b->size = 0;
	is_duplicate(a);
	comp_algo(a, b, ac, av);
//	print_stack(a);
//	print_stack(b);
//	ans = singleton();
//	printf("nb_cmd = %d\n", lst_size(ans));
//	print_stack(a);
//	print_stack(b);
	return (0);
}
