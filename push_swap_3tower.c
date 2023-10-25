/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3tower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:22:09 by cleguina          #+#    #+#             */
/*   Updated: 2023/10/24 18:04:39 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_3tower(t_stack **stack_origin, t_stack **stack_dest)
{
	while (ft_len_list(*stack_origin) > 3 && ft_order(*stack_origin) == 0)
	{
		ft_min_to_top(&(*stack_origin));
		if (ft_order(*stack_origin) == 0)
		{
			push(&(*stack_origin), &(*stack_dest));
			write(1, "pb\n", 3);
		}
		else
			break ;
	}
	ft_sort3(stack_origin);
}

void	ft_sort3(t_stack **stack)
{
	while (ft_order(*stack) == 0)
	{
		if ((*stack)->data > (*stack)->next->data)
		{
			interchange(stack);
			write(1, "sa\n", 3);
		}
		else if ((*stack)->data > ((*stack)->next->data))
		{
			to_last(stack);
			write(1, "ra\n", 3);
		}
		else if ((*stack)->next-> data > (ft_lst_last(*stack)-> data))
		{
			rotate(stack);
			write(1, "rra\n", 4);
		}
	}
}

void	ft_sort_2(t_stack **s)
{
	if (ft_order (*s) == 0)
	{
		interchange(s);
		write(1, "sa\n", 3);
	}
}
