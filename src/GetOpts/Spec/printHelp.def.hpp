template <typename OutputStream>
void
T::printHelp
(
	OutputStream && output_stream,
	char * argv0,
	size_t columns,
	size_t tabwidth,
	size_t indentation
) const
{
	size_t argv0_len = strlen (argv0);

	IO::Util::indent (std::forward <OutputStream> (output_stream), indentation);
	output_stream . print ("Usage:  ");
	output_stream . write (argv0, argv0_len);
	output_stream . put (' ');
	output_stream . print (this -> usage_suffix);
	output_stream . put ('\n');

	output_stream . put ('\n');

	for
	(
		std::string line :
		IO::Util::justify
		(
			this -> description,
			columns - tabwidth * indentation
		)
	)
	{
		IO::Util::indent
		(
			std::forward <OutputStream> (output_stream),
			indentation
		);
		output_stream . print (line);
		output_stream . put ('\n');
	}

	output_stream . put ('\n');

	for (const OptionSpec::T & option_spec : this -> options)
	{
		IO::Util::indent
		(
			std::forward <OutputStream> (output_stream),
			indentation
		);
		if (option_spec . short_form)
		{
			output_stream . put ('-');
			output_stream . put (option_spec . short_form);
			if (! option_spec . long_form . empty ())
			{
				output_stream . print (", --");
				output_stream . print (option_spec . long_form);
			}
		}
		else if (! option_spec . long_form . empty ())
		{
			output_stream . print ("--");
			output_stream . print (option_spec . long_form);
		}
		output_stream . put ('\n');

		for
		(
			std::string line :
			IO::Util::justify
			(
				option_spec . description,
				columns - tabwidth * (indentation + 1)
			)
		)
		{
			IO::Util::indent
			(
				std::forward <OutputStream> (output_stream),
				indentation + 1
			);
			output_stream . print (line);
			output_stream . put ('\n');
		}

		output_stream . put ('\n');
	}
}
