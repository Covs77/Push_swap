/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3tower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:22:09 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/22 16:52:01 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_3tower(t_stack **stack_origin, t_stack **stack_dest)
{
	while (ft_len_list(*stack_origin) > 3 && ft_order(*stack_origin) == 0)
	{
		ft_min_to_top(stack_origin);
		if (ft_order(*stack_origin) == 0)
		{
			push(stack_origin, stack_dest);
			write(1, "pb\n", 3);
		}
		else
			break ;
	}
	ft_sort3(stack_origin);
}

void	ft_sort3(t_stack **stack)
{
	int	max;

	max = ft_max(*stack);
	if ((*stack)->data == max)
		move_to_last(stack, NULL, "ra");
	if ((*stack)->next->data == max)
		move_rotate(stack, NULL, "rra");
	if ((*stack)->data > (*stack)->next->data)
		move_interchange(stack, NULL, "sa");
}

void	ft_sort_2(t_stack **s)
{
	if (ft_order (*s) == 0)
		move_interchange(s, NULL, "sa");
}

// pone el mas pequeño encima ---solo 3 elementos---
void	ft_on_top(t_stack **s, int counter)
{
	int	len;

	len = (ft_len_list(*s) / 2);
	if (counter >= len)
		move_rotate(s, NULL, "rra");
	else if (counter == 1)
		move_interchange(s, NULL, "sa");
	else
		move_to_last(s, NULL, "ra");
}

//funcion que pone el menor encima del stack (hasta 5 elementos)
void	ft_min_to_top(t_stack **stack)
{
	int		min;
	t_stack	*pointer;
	int		contador;

	min = ft_min(*stack);
	contador = 0;
	pointer = *stack;
	if (pointer->data == min)
		return ;
	else
	{
		while (pointer->data != min)
		{
			pointer = pointer->next;
			contador++;
			if (pointer->data == min)
			{
				ft_on_top(stack, contador);
				pointer = *stack;
			}
		}
	}
}
