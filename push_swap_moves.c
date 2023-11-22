/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:59:47 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/22 19:55:11 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

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

int	ft_both_cost(t_stack **a, t_stack **b, int pos)
{
	t_stack	*aux_a;
	t_stack	*aux_b;

	if (a != NULL)
	{
		aux_a = *a;
		while (aux_a->pos != pos)
			aux_a = aux_a->next;
		return (aux_a->cost_a);
	}
	else
	{
		aux_b = *b;
		while (aux_b->pos != pos)
			aux_b = aux_b->next;
		return (aux_b->cost_b);
	}
}

void	ft_sort_on_top_both(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	int		cost_a;
	int		cost_b;

	cost_a = ft_both_cost(a, NULL, pos_a);
	cost_b = ft_both_cost(NULL, b, pos_b);
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
