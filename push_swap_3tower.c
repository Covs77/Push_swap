/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3tower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:22:09 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/21 19:13:31 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_3tower(t_stack **stack_origin, t_stack **stack_dest)
{
	while (ft_len_list(*stack_origin) > 3 && ft_order(*stack_origin) == 0)
	{
		ft_min_to_top(stack_origin);
		if (ft_order(*stack_origin) == 0)
		{
			push(stack_origin, stack_dest);
			write(1, "pb\n", 3);
		}
		else
			break ;
	}
	ft_sort3(stack_origin);
}

void	ft_sort3(t_stack **stack)
{
	int	max;

	max = ft_max(*stack);
	if ((*stack)->data == max)
		move_to_last(stack, NULL, "ra");
	if ((*stack)->next->data == max)
		move_rotate(stack, NULL, "rra");
	if ((*stack)->data > (*stack)->next->data)
		move_interchange(stack, NULL, "sa");
}

void	ft_sort_2(t_stack **s)
{
	if (ft_order (*s) == 0)
		move_interchange(s, NULL, "sa");
}

char	*ft_strjoin_free(char *s1, char  *s2)
{
	char	*s3;
	size_t	l_s1;
	size_t	l_s2;
	size_t	l_s3;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	l_s3 = l_s1 + l_s2;
	if (!s1 && !s2)
		return (0);
	s3 = malloc (sizeof(char) * l_s3 + 1);
	if (s3 == NULL)
		return (0);
	s3 = ft_memcpy(s3, s1, l_s1);
	s3 = s3 + l_s1;
	s3 = ft_memcpy(s3, s2, l_s2 + 1);
	free(s1);
	return (s3 - (l_s1));
}


void	ft_free_matrix(char **str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free (str);
	}
}