#ifndef PRINT_MEMORY_H
# define PRINT_MEMORY_H

# include <unistd.h>
# include <string.h>

# define MEM_LINE_LENGTH 69

void	print_memory(const void *addr, size_t size);

#endif
