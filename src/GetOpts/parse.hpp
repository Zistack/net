void
parse (int argc, char ** argv, const Spec::T & spec)
{
	parse (argc, argv, spec, nullptr);
}

void
parse (int argc,
    char ** argv,
    const Spec::T & spec,
    std::function<void(char *)> nonOptAction)
{
	ArgStream::T arg_stream (argc, argv);
	arg_stream.get ();

	char * arg;

	while ((arg = arg_stream.get ()))
	{
		if (arg[0] == '-')
		{
			validate (arg);

			if (arg[1] == '-')
			{
				char * option_name = &arg[2];

				if (spec.contains (option_name))
				{
					const OptionSpec::T & option = spec.at (option_name);

					char * argument = nullptr;

					if (isNonOption (arg_stream.peek ()) &&
					    option.takesArgument ())
					{
						argument = arg_stream.get ();
					}

					processOption (option, argument);
				}
				else
				{
					throw Failure::Error::T (
					    std::string ("Unrecognized option: --") + option_name +
					    "\n");
				}
			}
			else
			{
				ShortOptStream::T option_stream (&arg[1]);

				char option_name;

				while ((option_name = option_stream.get ()))
				{
					if (spec.contains (option_name))
					{
						const OptionSpec::T & option = spec.at (option_name);

						char * argument = nullptr;

						if (isNonOption (arg_stream.peek ()) &&
						    !option_stream.peek () && option.takesArgument ())
						{
							argument = arg_stream.get ();
						}

						processOption (option, argument);
					}
					else
					{
						throw Failure::Error::T (
						    std::string ("Unrecognized option: -") +
						    std::string ({option_name}) + "\n");
					}
				}
			}
		}
		else
		{
			if (!nonOptAction)
				return;
			else
				nonOptAction (arg);
		}
	}
}
