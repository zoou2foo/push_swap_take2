/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriejean <valeriejean@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 08:26:43 by vjean             #+#    #+#             */
/*   Updated: 2022/10/09 19:29:04 by valeriejean      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack{
	int				value;
	int				index;
	int				size_max;
	int				pos_a;
	int				pos_b;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// value: nombre à trier
// index: son index dans toute la liste à trier
// size_max: savoir le nombre total d'éléments à tr ier
// pos_a: position actuelle dans la pile de A
// pos_b: position actuelle dans la pile de B
// target_pos: position cible dans la pileA (quand dans la pileB)
// cost_a: combien actions pour faire pivoter A (pour aller au sommet de A)
// cost_b: combien actions pour faire pivoter B (pour aller au sommet de B)
// next: pointeur pour le prochain élément

/* check arguments */
void	is_alpha(char **av);
void	check_numbers(char **av);
int		check_doubles(t_stack *stack_a);
void	check_input(char **av, t_stack **stack_a);

/* to deal with linked list */
void	fill_lst(char **av, t_stack *stack_a);
int		check_if_sorted(t_stack *stack_a);
void	check_how_many(t_stack **stack_a, t_stack **stack_b);
int		check_if_sorted_for_two(t_stack *stack_a);
//, t_stack **stack_b pour check_how_many

/* all about setup of index and 📍position📍 in stacks */
void	setup_index(t_stack *stack_a);
void	find_pos_a(t_stack *stack_a);
void	find_pos_b(t_stack *stack_b);
int		find_bigger_index(t_stack *stack_a);
t_stack	*find_node_w_lower_index(t_stack *stack_a);
int		finding_median(t_stack **stack_a);
void	finding_all_pos(t_stack *stack_a, t_stack *stack_b);
void	find_target_pos(t_stack **stack_a, t_stack **stack_b);

/* all about the 🔄 movements 🔄 */
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

/* Everything algorithms ⬇️ HERE ⬇️ */
void	algo_for_two(t_stack **stack_a);
void	algo_for_three(t_stack **stack_a);
void	algo_three_versa(t_stack **stack_a);
void	move_almost_all_in_b(t_stack **stack_a, t_stack **stack_b);
void	do_algo_more_three(t_stack **stack_a);
void	check_only_three_in_a(t_stack **stack_a, t_stack **stack_b);

/* all about the 💲 cost 💲 */
void	find_cost(t_stack **stack_a, t_stack **stack_b);
void	find_cheapest_cost(t_stack **stack_a, t_stack **stack_b);
int		get_abs_nb(int nb);
void	plan_moves(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

/* Yeah I'm free! Free fallin'!! */
void	free_node(t_stack *stack_a);

/* modified functions from libft */
t_stack	*lstlast(t_stack *stack_a);
t_stack	*lstadd_front(t_stack **stack_a, t_stack *head);
int		lstsize(t_stack *stack_a);

/* useless functions. Just to help me */
void	print_split(char **av);
void	print_stack(t_stack **stack_a, t_stack **stack_b);
//void	print_lst(t_stack **stack_a);
//void	print_lst_b(t_stack **stack_b);

#endif
