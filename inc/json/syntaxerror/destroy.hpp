void
destroy (T * syntax_error)
{
	clean (syntax_error);
	free (syntax_error);
}
