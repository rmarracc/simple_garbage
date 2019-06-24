#include "garbage.h"

void	*gextend(t_garbage *gc)
{
	void	**tmp;

	if (!(tmp = (void**)malloc(sizeof(void*) * gc->size)))
		return (NULL);
	memcpy((void*)tmp, (void*)gc->ptr_tab, gc->size * sizeof(void*));
	if (!(gc->ptr_tab = (void**)realloc(gc->ptr_tab, sizeof(void*) * (gc->size + EXTEND_SIZE))))
	{
		gc->ptr_tab = tmp;
		return (NULL);
	}
	free(tmp);
	gc->size += EXTEND_SIZE;
	return (gc);
}
