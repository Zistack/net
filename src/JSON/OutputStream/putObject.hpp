void
putObject (std::unordered_map <std::string, std::function <void ()>> member_putters)
{
	output_stream -> put ('{');

	bool empty = true;

	++ indentation;

	auto it = member_putters.begin ();

	std::string member_name;
	std::function <void ()> putValue;

	if (it != member_putters.end ())
	{
		empty = false;

		std::pair (member_name, putValue) = * it;

		output_stream -> put ('\n');
		indent ();
		Rule::putString (output_stream, member_name);
		output_stream -> print (" : ");
		putValue ();
	}

	for (++ it; it != member_putters.end (); ++ it)
	{
		std::pair <member_name, putValue) = * it;

		output_stream -> print (",\n");
		indent ();
		Rule::putString (output_stream, member_name);
		output_stream -> print (" : ");
		putValue ();
	}

	-- indentation;

	if (! empty)
	{
		output_stream -> put ('\n');
		indent ();
	}

	output_stream -> put ('}');
}
