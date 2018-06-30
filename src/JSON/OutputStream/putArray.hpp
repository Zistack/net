void
putArray (std::function <bool ()> isValue, std::function <void ()> putValue)
{
	output_stream -> put ('[');

	bool empty = true;

	++ indentation;

	if (isValue ())
	{
		empty = false;

		output_stream -> put ('\n');
		indent ();
		putValue ();
	}

	while (isValue ())
	{
		output_stream -> print (",\n");
		indent ();
		putValue ();
	}

	-- indentation;

	if (! empty)
	{
		output_stream -> put ('\n');
		indent ();
	}

	output_stream -> put (']');
}

