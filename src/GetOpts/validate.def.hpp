void
validate (char * option_string)
{
	char * c;
	for (c = option_string; * c; ++ c)
	{
		if (* c < 32 || * c > 126)
		{
			throw Failure::Error::T ("Illegal character in option string\n");
		}
	}
}
