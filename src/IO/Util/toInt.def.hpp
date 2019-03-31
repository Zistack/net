int64_t
toInt (const std::string & string, int base)
{
	try
	{
		return std::stoll (string, NULL, base);
	}
	catch (std::out_of_range e)
	{
		throw Failure::Error::T
		(
			std::string ("Failed to convert number string to integer:\n") +
				e.what () +
				"\n"
		);
	}
}
