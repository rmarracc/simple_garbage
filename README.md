# simple_garbage
Minimalist garbage collector in C language

## Installation

### Clone

- Clone this repo using `git clone https://github.com/rmarracc/simple_garbage`

### Build

- Simply build the library with `make` in the cloned folder

## Usage

- Link your program with the following flags : `-L [library_folder]/ -lgarbage`

### Man

- At the beginning of your program, declare a t_garbage type variable
- Then, directly execute the function `ginit` with the t_garbage address on parameter
- `ginit` returns a NULL pointer if the memory allocation fails, else it returns the t_garbage address
- Replace all your program `malloc` calls with `gmalloc`, which additionaly take the t_garbage address
- `gmalloc`, as the malloc function does, return a NULL pointer if the memory allocation fails
- Before exiting your program, execute `gfree` to free all your malloc'ed pointers and the garbage collector itself

### Prototypes

- void	*gmalloc(t_garbage *gc, size_t size);
- void	*ginit(t_garbage *gc);
- void	*gextend(t_garbage *gc);
- void	gfree(t_garbage *gc);

## Notes

- The `gextend` function extends the garbage collector size, the function is called by gmalloc if the maximum size of the t_garbage is reached, so you don't need to use it
- This is a lazy solution to free all your allocated memory, you can also declare a global t_garbage and use the macros `#define malloc(x) gmalloc(address, x)` and `#define free(x) gfree(address)`, but it causes performance loss since the garbage collector store all the addresses in a inner array
- This library handles every allocation errors, please post an issue if you notice an unexpected error or a crash caused by my library
