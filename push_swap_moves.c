/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:59:47 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/15 20:47:56 by cleguina         ###   ########.fr       */
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

void	ft_sort_on_top(t_stack **s, int pos, char *pila)
{
	int 	i;
	t_stack *aux;
	
	aux = *s;
	while (aux->pos != pos)
		aux = aux->next;
	
	i = aux->cost_a;
	while ((*s)-> pos != pos)
	{
		if (i < 0)
		{
			if (ft_strcmp (pila, "a") == 0)
				move_rotate(s, NULL, "rra");
			else
				move_rotate(NULL, s, "rrb");
		}
		else
		{
			if (ft_strcmp (pila, "a") == 0)
				move_to_last(s, NULL, "ra");
			
			else
				move_to_last(NULL, s, "rb");
		}
		
	}
}


void	ft_sort_on_top_both(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	while ((*a)->pos != pos_a || (*b)->pos != pos_b)
	{
		if ((*a)->cost_a < 0 && (*b)->cost_b < 0)
			move_rotate(a, b, "rrr");
		if ((*a)->cost_a > 0 && (*b)->cost_b > 0)
			move_rotate(a, b, "rr");
		else
		{
			ft_sort_on_top(a, pos_a, "a");
			ft_sort_on_top(b, pos_b, "b");
		}
	}
}

int ft_find_lower_cost(t_stack *a, t_stack *b)
{
	int min;
	t_stack *aux_b;
	t_stack *aux_a;
	int pos_a;
		
	min = 0;
	aux_b = b;
	aux_a = a;
	pos_a = 0;
	while (b && b->next != NULL)
	{
		pos_a = ft_find_hole(aux_a, b->pos);
		
		if (ft_total_cost (pos_a, a, b) == min)
			return (aux_b->pos);
		if (aux_b)
			aux_b = aux_b->next;
		else 
		{
			min++;
			aux_b = b;
		}
	}
	//printf ("elemento de b a mover: %d\n", aux_b->pos);
	return (aux_b->pos);
}