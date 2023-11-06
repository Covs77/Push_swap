/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:16:00 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/06 20:49:21 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_midi_list (t_stack *s)
{
	return (ft_len_list(s) / 2);
}


/// NO CALCULA BIEN LOS COSTES!!!! DEBE SER DECRECIENTE
// SIENDO 0 EL DE ABAJO.
void ft_cost_b(t_stack **b)
{
	int i;
	int midi;
	t_stack *aux;

	aux = *b;
	i = 0;
	midi = 0;
	midi = ft_midi_list(*b);
	printf ("Midi. %d", midi);
	while (aux)
	{
		if (i <= midi)
		{
			aux->cost_b = i;
			i++;
		}
		else
		{
			aux->cost_b = i * - 1;
			i++;;
		}
		aux = aux->next;
	} 
	
}