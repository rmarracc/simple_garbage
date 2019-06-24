#include "garbage.h"

void	*ginit(t_garbage *gc)
{
	if (!(gc->ptr_tab = (void**)malloc(sizeof(void*) * EXTEND_SIZE)))
		return (NULL);
	gc->size = EXTEND_SIZE;
	gc->head = 0;
	return (gc);
}
