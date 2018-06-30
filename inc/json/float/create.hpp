T *
create ()
{
	T * float = (T *) malloc (sizeof (T));
	init (float);
	return float;
}
