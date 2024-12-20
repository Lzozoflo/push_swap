/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:42:55 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/20 11:30:18 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d -> ", stack->content);
		stack = stack->next;
	}
	printf("NULL\n");
}

void	ft_print_two_stack(t_stack *a, t_stack *b)
{
	printf("\nStack A\t:\t");
	ft_print_stack(a);
	printf("\nStack B\t:\t");
	ft_print_stack(b);
}


void test_to_print_lst(t_stack	**head_a, t_stack **head_b)
{
	t_stack *tmp;

	tmp = *head_a;
	ft_print_two_stack(*head_a, *head_b);

	printf("\n---Before pre_sorting---\n");
	ft_sort(head_a, head_b);
	printf("\n---After pre_sorting---\n");

	ft_print_two_stack(*head_a, *head_b);
}

