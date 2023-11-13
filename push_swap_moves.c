/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:59:47 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/13 20:52:55 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

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

void	ft_sort_on_top(t_stack **s, int pos)
{
	t_stack *aux;
	int 	i;
	
	aux = *s;
	i = (*s)->cost_a;
	while ((*s)-> pos != pos)
	{
		if (i < 0)
			move_rotate(s, NULL, "rra");
		else
			move_to_last(s, NULL, "ra");
	}
	//printf("ontop");
	//ft_print_list(*s);
}


void	ft_sort_on_top_both(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	while ((*a)->pos != pos_a || (*b)->pos != pos_b)
	{
		if ((*a)->cost_a < 0 && (*b)->cost_b < 0)
			move_rotate(a, b, "rrr");
		else if ((*a)->cost_a > 0 && (*b)->cost_b > 0)
			move_rotate(a, b, "rr");
		else
		{
			ft_sort_on_top(a, pos_a);
			ft_sort_on_top(b, pos_b);
		}
	}
}


int ft_find_lower_cost(t_stack *b)
{
	int min;
	t_stack *aux;
		
	min = 0;
	aux = b;
	while ((abs(aux->cost_a) + (abs(aux->cost_b))) != min)
	{
		if (aux && aux->next)
			aux = aux->next;
		else
			min++;
			aux = b;
	}
	return (aux->pos);
}