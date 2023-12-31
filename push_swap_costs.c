/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:16:00 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/20 16:48:59 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_midi_list(t_stack *s)
{
	return (ft_len_list(s) / 2);
}

void	ft_cost_b(t_stack **b)
{
	int		i;
	int		j;
	int		midi;
	t_stack	*aux;

	aux = *b;
	i = 0;
	midi = 0;
	j = 0;
	midi = ft_midi_list(*b);
	if (ft_len_list(*b) % 2 != 0)
		j = midi;
	else
		j = midi -1;
	while (aux)
	{
		if (i <= midi)
			aux->cost_b = (i++);
		else
			aux->cost_b = (j--) * -1;
		aux = aux->next;
	}
}

void	ft_cost_a(t_stack **a)
{
	int		i;
	int		j;
	int		midi;
	t_stack	*aux;

	aux = *a;
	i = 0;
	midi = 0;
	j = 0;
	midi = ft_midi_list(*a);
	if (ft_len_list(*a) % 2 != 0)
		j = midi;
	else
		j = midi -1;
	while (aux)
	{
		if (i <= midi)
			aux->cost_a = (i++);
		else
			aux->cost_a = (j--) * -1;
		aux = aux->next;
	}
}

int	ft_find_hole(t_stack *s, int pos)
{
	t_stack	*aux;
	int		i;

	i = pos + 1;
	aux = s;
	while (aux->pos != i && aux && aux->next)
	{
		while (aux->pos != i && aux && aux->next)
			aux = aux->next;
		if (aux->pos == i)
			return (i);
		else
		{
			i++;
			aux = s;
		}
	}
	return (i);
}

int	ft_total_cost(int pos_a, t_stack *a, t_stack *b)
{
	while (a && a->pos != pos_a)
		a = a->next;
	if (a->cost_a > 0 && b->cost_b > 0)
	{
		if (a->cost_a > b->cost_b)
			return (a->cost_a);
		else
			return (b->cost_b);
	}
	else if (a->cost_a < 0 && b->cost_b < 0)
	{
		if (a->cost_a < b->cost_b)
			return (a->cost_a);
		else
			return (b->cost_b);
	}
	else
		return (abs (a->cost_a) + abs (b->cost_b));
}
