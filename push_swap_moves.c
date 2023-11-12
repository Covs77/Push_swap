/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:59:47 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/12 18:12:38 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

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

void	ft_sort_top(t_stack **s, int pos)
{
	t_stack *aux;

	aux = *s;
	while (aux->pos != pos)
		aux = aux->next;
	// colocar el nodo aarriba , sobre el que haré el push.

	//if (aux->cost_a < 0)
	//	move_rotate(s, NULL, "rra");
} 

