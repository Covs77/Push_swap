/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:59:47 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/20 20:49:44 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

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

void	ft_top_stack(int i, t_stack **s, char *pila)
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

void	ft_sort_on_top(t_stack **s, int pos, char *pila)
{
	int		i;
	t_stack	*aux;

	aux = *s;
	while (aux->pos != pos)
		aux = aux->next;
	if (ft_strcmp (pila, "a") == 0)
		i = aux->cost_a;
	else
		i = aux->cost_b;
	while ((*s)-> pos != pos)
		ft_top_stack(i, s, pila);
}


// reducir esta funcion

void	ft_sort_on_top_both(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;
	int		cost_a;
	int		cost_b;

	aux_a = *a;
	while (aux_a->pos != pos_a)
		aux_a = aux_a->next;
	aux_b = *b;
	while (aux_b->pos != pos_b)
		aux_b = aux_b->next;
	cost_a = aux_a->cost_a;
	cost_b = aux_b->cost_b;
	while ((*a)->pos != pos_a || (*b)->pos != pos_b)
	{
		if (((cost_a) < 0) && ((cost_b) < 0))
		{
			move_rotate(a, b, "rrr");
			cost_a++;
			cost_b++;
		}
		if ((cost_a > 0) && (cost_b) > 0)
		{
			move_to_last(a, b, "rr");
			cost_a--;
			cost_b--;
		}
		else
		{
			ft_sort_on_top(a, pos_a, "a");
			ft_sort_on_top(b, pos_b, "b");
		}
	}
}

int	ft_find_lower_cost(t_stack *a, t_stack *b)
{
	int		min;
	t_stack	*aux_b;
	t_stack	*aux_a;
	int		pos_a;
	int		total_cost;

	min = 0;
	aux_b = b;
	aux_a = a;
	total_cost = 0;
	while (aux_b)
	{
		pos_a = ft_find_hole(aux_a, aux_b->pos);
		total_cost = ft_total_cost (pos_a, a, aux_b);
		if (total_cost == min)
			return (aux_b->pos);
		else
			aux_b = aux_b->next;
		if (aux_b == NULL)
		{
			min++;
			aux_b = b;
		}
	}
	return (aux_b->pos);
}
