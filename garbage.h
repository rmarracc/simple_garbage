#ifndef GARBAGE_H
# define GARBAGE_H

# define EXTEND_SIZE 100

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct			s_garbage
{
	void				**ptr_tab;
	size_t				size;
	size_t				head;
}						t_garbage;

void	*gmalloc(t_garbage *gc, size_t size);
void	*ginit(t_garbage *gc);
void	*gextend(t_garbage *gc);
void	gfree(t_garbage *gc);

#endif