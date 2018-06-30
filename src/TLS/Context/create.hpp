T *
create (Config::T * config)
{
	T * context = (T *) malloc (sizeof (T));
	if (init (context, config))
	{
		free (context);
		context = NULL;
	}
	return context;
}
