void
destroy (T * key_pair)
{
	clean (key_pair);
	free (key_pair);
}
