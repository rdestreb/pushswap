/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 12:43:46 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/20 18:02:45 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*get_flag(void)
{
	static int *flag = NULL;

	if (!flag)
		flag = (int *)ft_memalloc(sizeof(int));
	return (flag);
}

static void	print_help(void)
{
	ft_putstr_fd("usage: ./push_swap -help [-vnbri] [digit1 digit2 ...]\n", 2);
	ft_putstr_fd("  Default action is to sort a list without duplicate of\n", 2);
	ft_putstr_fd("  integers passed as arguments, then write the actions\n", 2);
	ft_putstr_fd("  done in stdout. 2 algos are used, compared,\n", 2);
	ft_putstr_fd("  then the best one (shorter answer) is picked.\n\n", 2);
	ft_putstr_fd("    -v  verbose\n", 2);
	ft_putstr_fd("    -n  write number of actions needed in stdout\n", 2);
	ft_putstr_fd("    -b  indicate which algo is better\n", 2);
	ft_putstr_fd("    -r  use only the 'Rot-Swap' algo\n", 2);
	ft_putstr_fd("    -i  use only the 'Insertion' algo\n", 2);
	exit(2);
}

static void	illegal_option(char *arg)
{
	int	i;

	i = 0;
	while (arg[++i])
	{
		if (arg[i] != 'v' && arg[i] != 'n' && arg[i] != 'b' && arg[i] != 'r'
			&& arg[i] != 'i')
		{
			ft_putstr_fd("push_swap: illegal option -- ", 2);
			ft_putchar_fd(arg[i], 2);
			ft_putstr_fd("\nusage: push_swap [-vnbri] [digit1 digit2 ...]\n", 2);
			exit(2);
		}
	}
}

int			init_flags(int ac, char **av)
{
	int	i;
	int	*flag;

	i = 0;
	flag = get_flag();
	while (++i < ac && av[i][0] == '-' && !(ft_isdigit(av[i][1])))
	{
		if (!(ft_strcmp(av[i], "-help")))
			print_help();
		illegal_option(av[i]);
		if(ft_strchr(av[i], 'v'))
			*flag |= VERBOSE;
		if(ft_strchr(av[i], 'n'))
			*flag |= NB_OP;
		if(ft_strchr(av[i], 'b'))
			*flag |= BEST_ALGO;
		if(ft_strchr(av[i], 'r'))
			*flag |= R_S;
		if(ft_strchr(av[i], 'i'))
			*flag |= INS;
	}
	return (i - 1);
}
