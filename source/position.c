#include "../push_swap.h"

/* get_position:
*	Assigns a position to each element of a stack from top to bottom
*	in ascending order.
*	Example stack:
*		value:		 3	 0	 9	 1
*		index:		[3]	[1]	[4]	[2]
*		position:	<0>	<1>	<2>	<3>
*	This is used to calculate the cost of moving a certain number to
*	a certain position. If the above example is stack b, it would cost
*	nothing (0) to push the first element to stack a. However if we want to
*	push the highest value, 9, which is in third position, it would cost 2 extra
*	moves to bring that 9 to the top of b before pushing it to stack a.
*/
static void	get_position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->current_position = i;
		temp = temp->next;
		i++;
	}
}

/* get_lowest_index_position:
*	Gets the current position of the element with the lowest index
*	within a stack.
*/
int	get_the_lowest_index(t_stack **stack)
{
	t_stack	*temp;
	int		lowest_index;
	int		lowest_pos;

	temp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = temp->current_position;
	while (temp)
	{
		if (temp->index < lowest_index)
		{
			lowest_index = temp->index;
			lowest_pos = temp->current_position;
		}
		temp = temp->next;
	}
	return (lowest_pos);
}

/* get_target:
*	Picks the best target position in stack A for the given index of
*	an element in stack B. First checks if the index of the B element can
*	be placed somewhere in between elements in stack A, by checking whether
*	there is an element in stack A with a bigger index. If not, it finds the
*	element with the smallest index in A and assigns that as the target position.
*	--- Example:
*		target_pos starts at INT_MAX
*		B index: 3
*		A contains indexes: 9 4 2 1 0
*		9 > 3 && 9 < INT_MAX 	: target_pos updated to 9
*		4 > 3 && 4 < 9 			: target pos updated to 4
*		2 < 3 && 2 < 4			: no update!
*	So target_pos needs to be the position of index 4, since it is
*	the closest index.
*	--- Example:
*		target_pos starts at INT_MAX
*		B index: 20
*		A contains indexes: 16 4 3
*		16 < 20					: no update! target_pos = INT_MAX
*		4  < 20					: no update! target_pos = INT_MAX
*		3  < 20					: no update! target_pos = INT_MAX
*	... target_pos stays at INT MAX, need to switch strategies.
*		16 < 20					: target_pos updated to 20
*		4  < 20					: target_pos updated to 4
*		3  < 20					: target_pos updated to 3
*	So target_pos needs to be the position of index 3, since that is
*	the "end" of the stack.
*/
static int	get_target(t_stack **a, int b_idx,
								int target_idx, int target_pos)
{
	t_stack	*temp_a;

	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index > b_idx && temp_a->index < target_idx)
		{
			target_idx = temp_a->index;
			target_pos = temp_a->current_position;
		}
		temp_a = temp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index < target_idx)
		{
			target_idx = temp_a->index;
			target_pos = temp_a->current_position;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

/* get_target_position:
*	Assigns a target position in stack A to each element of stack A.
*	The target position is the spot the element in B needs to
*	get to in order to be sorted correctly. This position will
*	be used to calculate the cost of moving each element to
*	its target position in stack A.
*/
void	get_the_target_position(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;
	int		target_pos;

	temp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (temp_b)
	{
		target_pos = get_target(a, temp_b->index, INT_MAX, target_pos);
		temp_b->target_position = target_pos;
		temp_b = temp_b->next;
	}
}