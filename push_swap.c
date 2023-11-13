/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:29:21 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/13 19:14:42 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	char	**str;
	int		error;

	error = 0;
	stack_a = NULL;
	if (argc > 1)
	{
		str = ft_read_arg(argc, argv);
		error = ft_check_inputs(str);
		if (error == 1)
		{
			ft_error(error);
			return (0);
		}
		stack_a = ft_make_list(str);
		ft_get_pos(stack_a, str);
		ft_sort_out(stack_a, argc);
	}
	
	ft_error(error);
	//printf ("ordenada");
	//ft_print_list(*stack_a);
	ft_free(stack_a);
	return (0);
}
