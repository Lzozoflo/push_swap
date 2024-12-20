/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:42:55 by fcretin           #+#    #+#             */
/*   Updated: 2024/12/20 10:10:39 by fcretin          ###   ########.fr       */
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
	printf("\n--->	Stack A\t:\t");
	ft_print_stack(a);
	printf("\n--->	Stack B\t:\t");
	ft_print_stack(b);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int test_to_print_lst(t_stack	**head_a, t_stack **head_b)
{

	printf("Before");
	ft_print_two_stack(*head_a, *head_b);
	printf("\n");
	ft_pre_sort(head_a, head_b);
	ft_print_two_stack(*head_a, *head_b);// one sort
	ft_idk(void);

	return (is_sorted(*head_a));
}

