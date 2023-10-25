/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:46:56 by cleguina          #+#    #+#             */
/*   Updated: 2023/10/24 18:08:28 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "./libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

int		ft_len_list(t_stack *stack);
void	ft_print_list(t_stack *stack);
t_stack	*ft_lst_last(t_stack *lst);
t_stack	*ft_delete_first(t_stack *lista);
t_stack	*ft_add_back(t_stack *stack, t_stack *new);
char	**ft_read_arg(int argc, char **argv);
int		ft_check_inputs(char **str);
t_stack	**ft_make_list(char **str);
void	ft_new_nodo(t_stack **stack, int valor);
void	ft_error(int error);
int		ft_medium(t_stack *stack);
int		ft_order(t_stack *stack);
void	ft_check_moves(t_stack *stack_a, t_stack *stack_b);
t_stack	*ra(t_stack *stack);
t_stack	*rra(t_stack *stack);
t_stack	*sa(t_stack *stack);
void	push(t_stack **stack_origin, t_stack **stack_dest);
void	interchange(t_stack **stack);
void	rotate(t_stack **stack);
void	to_last(t_stack **stack);
void	ft_sort3(t_stack **stack);
void	ft_3tower(t_stack **stack_origin, t_stack **stack_dest);
void	ft_sort5(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_out(t_stack **stack_a, int argc);
//void	ft_move_max(t_stack **s, t_stack **dest);
int		ft_min(t_stack *stack);
void	ft_min_to_top(t_stack **stack);
void	ft_on_top(t_stack **s, int counter);
int		ft_back_order(t_stack *stack);
void	ft_sort_2(t_stack **s);

#endif