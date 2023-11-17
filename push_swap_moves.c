/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:59:47 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/17 16:02:11 by cleguina         ###   ########.fr       */
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
	if (ft_strcmp (pila, "a") == 0)
		i = aux->cost_a;
	else 
		i = aux->cost_b;
		
	while ((*s)-> pos != pos)
	{
		//printf ("coste: %d\n", i);
		//printf ("pos: %d\n", (*s)->pos);
		//printf ("pos fin: %d\n", pos);
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
	int pos_a, total_cost;
		
	min = 0;
	aux_b = b;
	aux_a = a;
	pos_a = 0;
	total_cost = 0;
	while (aux_b)
	{
		pos_a = ft_find_hole(aux_a, aux_b->pos);
		//printf ("Tienes que ponerlo encima de: %d, ", pos_a);
		total_cost = ft_total_cost (pos_a, a, aux_b);
		if (total_cost == min)
			return (aux_b->pos);
		else
			aux_b = aux_b->next;
		if (aux_b == NULL)
		{
			min++;
			//printf ("min: %d\n", min);
			aux_b = b;
		}
	}
	//printf ("elemento de b a mover: %d\n", aux_b->pos);
	return (aux_b->pos);
}