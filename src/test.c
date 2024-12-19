/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:42:55 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/19 19:14:44 by fcretin          ###   ########.fr       */
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
	printf("Before");
	ft_print_two_stack(*head_a, *head_b);

	printf("\n");
	ft_sort(head_a, head_b);
	// (void)head_b;
	tmp = *head_a;
	// printf("\npre_sorting\n\n");
	// printf("ptr : %p\n", *head_a);
	// printf("ptr : %p\n\n", tmp);

	printf("\n\nAfter");
	ft_print_two_stack(*head_a, *head_b);
}

