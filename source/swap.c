#include "../push_swap.h"

/* swap:
*	Swaps the top 2 elements of a stack.
*	Does nothing if there is only one or no elements.
*/
static void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

/* sa:
*	Swaps the top 2 elements of stack a.
*	Prints "sa" to the standard output.
*/
void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

/* sb:
*	Swaps the top 2 elements of stack b.
*	Prints "sb" to the standard output.
*/
void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

/* ss:
*	Swaps the top 2 elements of stack a and the top 2 elements
*	of stack b.
*	Prints "ss" to the standard output.
*/
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}