uint64_t
toNum (const std::string & string)
{
	return toNum (string, 10);
}

uint64_t
toNum (const std::string & string, int base)
{
	try
	{
		return std::stoull (string, NULL, base);
	}
	catch (std::out_of_range e)
	{
		throw Failure::Error::T (
		    std::string ("Failed to convert number string to integer:\n") +
		    e.what () + "\n");
	}
}
