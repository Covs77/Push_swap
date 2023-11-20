/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:46:56 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/20 20:46:18 by cleguina         ###   ########.fr       */
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
	int				pos;
	int				cost_a;
	int				cost_b;
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
int		ft_min(t_stack *stack);
void	ft_min_to_top(t_stack **stack);
void	ft_on_top(t_stack **s, int counter);
int		ft_back_order(t_stack *stack);
void	ft_sort_2(t_stack **s);
void	ft_free(t_stack **s);
void	ft_big_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_up_or_down(t_stack **a, t_stack **b);
int		ft_max(t_stack *s);
void	ft_get_pos(t_stack **s, char **str);
void	ft_bubble_sort(char **str);
void	ft_cost(t_stack **a, t_stack **b);
void	ft_sort(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	ft_cost_b(t_stack **b);
void	ft_cost_a(t_stack **a);
int		ft_midi_list(t_stack *s);
void	move_to_last(t_stack **a, t_stack **b, char *move);
void	move_interchange(t_stack **a, t_stack **b, char *move);
void	move_rotate(t_stack **a, t_stack **b, char *move);
int		ft_find_hole(t_stack *s, int pos);
void	ft_sort_on_top(t_stack **s, int pos, char *pila);
void	ft_sort_on_top_both(t_stack **a, t_stack **b, int pos, int min);
int		ft_find_lower_cost(t_stack *a, t_stack *b);
int		ft_total_cost(int pos_a, t_stack *a, t_stack *b);
void	ft_top_stack(int i, t_stack **s, char *pila);
#endif