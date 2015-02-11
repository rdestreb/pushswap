/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:56:18 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/11 16:23:52 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	print_error(char *msg)
{
	ft_putstr_fd("Push_Swap : Error : ", 2);
	ft_putstr_fd(msg, 2);
	exit(2);
}

void	is_valid(char **av, int ac)
{
	int	i;
	int arg;

	if (ac < 3)
		print_error("Please enter at least 2 digits, without duplicates\n");
	arg = 0;
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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	is_valid(av, ac);
	a = create_stack(av, ac - 1, "a");
	b = create_stack(av, ac - 1, "b");
	b->size = 0;
	is_duplicate(a);
	print_stack(a);
	print_stack(b);
//	swap(a);
//	rotate(a);
	rev_rotate(a);
	print_stack(a);
	print_stack(b);
	rev_rotate(a);
	print_stack(a);
	print_stack(b);
	rev_rotate(a);
	print_stack(a);
	print_stack(b);
	rev_rotate(a);
	print_stack(a);
	print_stack(b);
	rev_rotate(a);
	print_stack(a);
	print_stack(b);
	rev_rotate(a);
	print_stack(a);
	print_stack(b);
	ft_memdel((void *)&a);
	ft_memdel((void *)&b);
	return (0);
}
