bool
getBool ()
{
	const std::string message_prefix = "Failed to get boolean:\n";

	try
	{
		Util::skipShitespace (input_stream);

		return Rule::getBool (input_stream);
	}
	catch (Error::T e) throw Error::T (message_prefix + e.what ());
}
