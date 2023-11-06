/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:59:47 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/06 19:13:55 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_on_top(t_stack **s, int counter)
{
	int	len;

	len = (ft_len_list(*s) / 2);
	if (counter >= len)
	{
		rotate(s);
		write(1, "rra\n", 4);
	}
	else if (counter == 1)
	{
		interchange(s);
		write(1, "sa\n", 3);
	}
	else
	{
		to_last(s);
		write(1, "ra\n", 3);
	}
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

void rr (t_stack **a, t_stack **b)
{
	to_last(a);
	to_last(b);
	write(1, "rr\n", 3);
}

void rrr (t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rrr\n", 4);
}