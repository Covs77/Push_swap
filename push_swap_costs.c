/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:16:00 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/07 17:53:14 by cova             ###   ########.fr       */
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
	midi = ft_midi_list(*b);
	j = midi -1;
	while (aux)
	{
		if (i <= midi)
		{
			aux->cost_b = i;
			i++;
		}
		else
		{
			aux->cost_b = j * -1;
			j--;
		}
		aux = aux->next;
	}
}
