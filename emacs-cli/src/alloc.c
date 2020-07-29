static void
malloc_unblock_input (void)
{
  if (block_input_in_memory_allocators)
    unblock_input ();
}
# define MALLOC_BLOCK_INPUT malloc_block_input ()
# define MALLOC_UNBLOCK_INPUT malloc_unblock_input ()
#else
# define MALLOC_BLOCK_INPUT ((void) 0)
# define MALLOC_UNBLOCK_INPUT ((void) 0)
#endif


void *
xmalloc (size_t size)
{
  void *val;

  MALLOC_BLOCK_INPUT;
  val = malloc (size);
  MALLOC_UNBLOCK_INPUT;

  if (!val && size)
    memory_full (size);
  MALLOC_PROBE (size);
  return val;
}
