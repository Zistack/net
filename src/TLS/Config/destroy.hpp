void
destroy (T * config)
{
	clean (config);
	free (config);
}
