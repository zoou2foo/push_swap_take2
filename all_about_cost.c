/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_about_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:22:20 by vjean             #+#    #+#             */
/*   Updated: 2022/10/13 13:46:05 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_b;
	int		size_a;
	int		size_b;

	head_b = *stack_b;
	size_a = lstsize(*stack_a);
	size_b = lstsize(*stack_b);
	while (*stack_b)
	{
		(*stack_b)->cost_b = (*stack_b)->pos_b;
		if ((*stack_b)->pos_b > (size_b / 2))
			(*stack_b)->cost_b = (size_b - (*stack_b)->pos_b) * -1;
		(*stack_b)->cost_a = (*stack_b)->target_pos;
		if ((*stack_b)->pos_b > (size_a / 2))
			(*stack_b)->cost_a = (size_a - (*stack_b)->target_pos) * -1;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = head_b;
}
// ^ relire et revoir en détails.
//(*stack_b)->cost_b = (*stack_b)->pos_a; : costb égale à la position où l'élément se trouve dans la pile b
//if ((*stack_b)->pos_b > (size_b / 2)): Si la pos de l'élément B est plus grand que la médiane, on fait ⬇️
//(*stack_b)->cost_b = (size_b - (*stack_b)->pos_b) * -1; :le coût de B devient (taille de b - pos de b; pour obtenir nb absolu) * -1, car on devra faire des rr
//(*stack_b)->cost_a = (*stack_b)->target_pos; : Puis, on passe au coût de A qui est égale à la position cible où l'élément B doit aller
//if ((*stack_b)->pos_b > (size_a / 2)) :Si la pos de l'élément B est plus grand que la médiane, on fait ⬇️
//(*stack_b)->cost_a = (size_a - (*stack_b)->target_pos) * -1; :le coût de A devient (taille de a - target_pos; pour obtenir nb absolu) * -1, car on devra faire des rr
//*stack_b = (*stack_b)->next; :puis, on passe au prochain node de B. Il faut assigner un cost de B et A pour chaque node de B

void	check_only_three_in_a(t_stack **stack_a, t_stack **stack_b)
{
	while (lstsize(*stack_a) > 3)
		do_pb(stack_a, stack_b);
}

void	find_cheapest_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;
	int		cost_a;
	int		cost_b;
	int		cheapest;

	cheapest = INT_MAX;
	head = *stack_b;
	while (*stack_b)
	{
		if (get_abs_nb((*stack_b)->cost_a) + get_abs_nb((*stack_b)->cost_b)
			< get_abs_nb(cheapest))
		{
			cheapest = get_abs_nb((*stack_b)->cost_a)
				+ get_abs_nb((*stack_b)->cost_b);
			cost_a = (*stack_b)->cost_a;
			cost_b = (*stack_b)->cost_b;
		}
		*stack_b = (*stack_b)->next;
	}
	*stack_b = head;
	plan_moves(stack_a, stack_b, cost_a, cost_b);
}
// ^ besoin t_stack tmp pour se balader dans la liste; int cheapest pour trouver
// le coût le moins cher; int cost_a et cost_b pour envoyer faire les séquences
// d'actions en conséquence du coût
// Notre int cheapest: on le start à INT_MAX, pour la jouer sûr selon le nb
// qu'on reçoit
//call une fonction de nb_abs pour trouver le nombre absolu des coûts. On ne
// veut pas tenir compte des signes. Si le nombre absolu de cost_a PLUS le 
// nombre absolu de cost est PLUS petit que le nombre absolu de cheapest, 
// cheapest ÉGALE nb abs de cost b + nb abs de cost a.
// int cost_a devient maintenant égale à struct cost_a et int cost_b devient
// égale à struct cost_b. On envoie à nb_abs cost_a et cost_b (from structure). 

int	get_abs_nb(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
