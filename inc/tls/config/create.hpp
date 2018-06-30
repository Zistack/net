T *
create ()
{
	T * config = (T *) malloc (sizeof (T));
	init (config);
	return config;
}
