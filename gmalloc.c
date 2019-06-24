#include "garbage.h"

void	*gmalloc(t_garbage *gc, size_t size)
{
	if (!(gc->ptr_tab))
		if (!(ginit(gc)))
			return (NULL);
	if ((gc->head + 1) >= gc->size)
		if (gextend(gc) == NULL)
			return (NULL);
	gc->ptr_tab[gc->head] = (void*)malloc(size);
	gc->head++;
	return (gc->ptr_tab[gc->head - 1]);
}