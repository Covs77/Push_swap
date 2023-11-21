/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:29:21 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/21 21:34:44 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

/* void ft_l(void)
{
	system("leaks -q push_swap");
} 
 */
int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	char	**str;
	int		error;

	//atexit(ft_l);
	error = 0;
	stack_a = NULL;
	if (argc > 1)
	{
		str = ft_read_arg(argc, argv);
		error = ft_check_inputs(str);
		if (error == 1)
		{
			ft_error(error);
			ft_free_matrix(str);
			return (0);
		}
		stack_a = ft_make_list(str);
		ft_get_pos(stack_a, str);
		if (ft_len_list(*stack_a) >= 2)
			ft_sort_out(stack_a, ft_len_list(*stack_a));
		ft_free_matrix(str);
		ft_free_list(stack_a);
	}
	ft_error(error);
	return (0);
}
