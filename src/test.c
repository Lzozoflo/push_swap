/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:42:55 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/08 17:16:10 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_data(t_data data)
{
		printf("\ndata -> count : %d\n", data.count);
		printf("data -> final_index_a : %d\n", data.final_index_a);
		printf("data -> final_index_b : %d\n", data.final_index_b);
}

void	ft_bcl_p_data(t_data *data)
{
	t_data	*tmp;

	tmp = data;
	while (tmp)
	{
		ft_print_data(*tmp);
		tmp = tmp->next;
	}
}

void	ft_print_stack(t_stack *stack,int i)
{
	while (stack)
	{
		if (i == 1)
			printf("%d -> ", stack->content);
		if (i == 2)
			printf("%d -> ", stack->final_index);
		if (i == 3)
			printf("%d -> ", stack->head_index);
		if (i == 4)
			printf("%d -> ", stack->top_bottom);
		stack = stack->next;
	}
	printf("NULL\n");
}

void	ft_print_two_stack(t_stack *a, t_stack *b)
{
	printf("\nStack A content\t\t:\t");
	ft_print_stack(a, 1);
	printf("\nStack A final\t\t:\t");
	ft_print_stack(a, 2);
	printf("\nStack A head\t\t:\t");
	ft_print_stack(a, 3);
	printf("\nStack A top bottom\t:\t");
	ft_print_stack(a, 4);
	printf("\n\nStack B content\t\t:\t");
	ft_print_stack(b, 1);
	printf("\nStack B final\t\t:\t");
	ft_print_stack(b, 2);
	printf("\nStack B head\t\t:\t");
	ft_print_stack(b, 3);
	printf("\nStack B top bottom\t:\t");
	ft_print_stack(b, 4);
}


void test_to_print_lst(t_stack	**head_a, t_stack **head_b)
{
	t_stack *tmp;

	tmp = *head_a;
	ft_print_two_stack(*head_a, *head_b);

	// ft_pre_sort(head_a, head_b);

	// ft_print_two_stack(*head_a, *head_b);
}

