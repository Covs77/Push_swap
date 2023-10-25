/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:59:47 by cleguina          #+#    #+#             */
/*   Updated: 2023/10/24 18:09:18 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

/* void	ft_move_max(t_stack **s, t_stack **dest)
{
	if ((*s)->data > (*s)->next->data)
	{
		push (s, dest);
		write(1, "pa\n", 3);
	}
	else
	{
		interchange(s);
		write(1, "sb\n", 3);
		push (s, dest);
		write(1, "pa\n", 3);
	}
} */

void ft_on_top(t_stack **s, int counter)
{
	int len;

	
	len = (ft_len_list(*s)/2);
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
void 	ft_min_to_top(t_stack **stack)
{
	int min;
	t_stack	*pointer;
	int contador;
	
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
	