T *
create ()
{
	T * syntax_error = (T *) malloc (sizeof (T));
	init (syntax_error);
	return syntax_error;
}
