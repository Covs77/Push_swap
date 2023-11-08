/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:16:00 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/08 18:53:21 by cleguina         ###   ########.fr       */
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
		j = midi - 1;
	else 
		j = midi; 
	while (aux)
	{
		if (i++ < midi)
		{
			aux->cost_b = i;
			//i++;
		}
		else
		{
			aux->cost_b = j * -1;
			j--;
		}
		aux = aux->next;
	}
}
