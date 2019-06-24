#include "garbage.h"

void	gfree(t_garbage *gc)
{
	size_t		i;

	i = 0;
	while (i < gc->head)
	{
		free(gc->ptr_tab[i]);
		i++;
	}
	free(gc->ptr_tab);
	gc->head = 0;
	gc->ptr_tab = NULL;
}