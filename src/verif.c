#include "push_swap.h"

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

void	is_duplicate(t_stack *st)
{
	int	i;
	int	j;

	i = -1;
	while (++i < st->size)
	{
		j = 0;
		while (i + ++j < st->size)
		{
			if (st->stack[i] == st->stack[i + j])
				print_error ("Duplicates in the stack !\n");
		}
	}
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
			print_error("At least one argument is not an INT digit\n");
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