std::string
getString ()
{
	const std::string message_prefix = "Failed to get string:\n";

	try
	{
		Util::skipWhitespace (input_stream);

		return Rule::getString (input_stream);
	}
	catch (Error::T e) throw Error::T (message_prefix + e.what ());
}
