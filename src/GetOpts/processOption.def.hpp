void
processOption (const OptionSpec::T & option, char * argument)
{
	if (argument)
	{
		option . argAction (argument);
	}
	else
	{
		if (option . requiresArgument ())
		{
			throw Failure::Error::T
			(
				"Argument required: " + option.name () + "\n"
			);
		}
		else option . flagAction ();
	}
}
