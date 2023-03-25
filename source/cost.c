#include "../push_swap.h"

/* get_cost:
*	Calculates the cost of moving each element of stack B into the correct
*	position in stack A.
*	Two costs are calculated:
*		cost_b represents the cost of getting the element to the top of the B stack
*		cost_a represents the cost of getting to the right position in stack A.
*	If the element is in the bottom half of the stack, the cost will be negative,
*	if it is in the top half, the cost is positive. 
*/

void get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		size_a;
	int		size_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	size_a = get_stack_size(temp_a);
	size_b = get_stack_size(temp_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->current_position;
		if (temp_b->current_position > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->current_position) * -1;
		temp_b->cost_a = temp_b->target_position;
		if (temp_b->target_position > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->target_position) * -1;
		temp_b = temp_b->next;
	}
}

/* do_cheapest_move:
*	Finds the element in stack B with the cheapest cost to move to stack A
*	and moves it to the correct position in stack A.
*/
void	cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (number_abs(tmp->cost_a) + number_abs(tmp->cost_b) < number_abs(cheapest))
		{
			cheapest = number_abs(tmp->cost_b) + number_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move(stack_a, stack_b, cost_a, cost_b);
}
