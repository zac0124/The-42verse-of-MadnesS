/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:24:21 by zmunkhja          #+#    #+#             */
/*   Updated: 2023/03/25 11:24:23 by zmunkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* rotate:
*	The top element of the stack is sent to the bottom.
*/
static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;

	temp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_bottom(*stack);
	temp->next = NULL;
	tail->next = temp;
}

/* ra:
*	Sends the top element of stack a to the bottom.
*	Prints "ra" to the standard output.
*/
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

/* rb:
*	Sends the top element of stack b to the bottom.
*	Prints "rb" to the standard output.
*/
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

/* rr:
*	Sends the top element of both stack a and stack b to the bottom
*	of their respective stacks.
*	Prints "rr" to the standard output.
*/
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
