void
destroy (T * context)
{
	clean (context);
	free (context);
}
