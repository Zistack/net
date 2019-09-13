template <typename ... Members>
template <typename InputStream>
T <Members ...>::T (InputStream && input_stream)
{
	IO::Util::expect (std::forward <InputStream> (input_stream), '{');

	Util::skipWhitespace (std::forward <InputStream> (input_stream));

	while (! IO::Util::test (std::forward <InputStream> (input_stream), '}'))
	{
		std::string op =
			Rule::getOp (std::forward <InputStream> (input_stream));

		Util::skipWhitespace (std::forward <InputStream> (input_stream));

		std::string identifier =
			Rule::getIdentifier (std::forward <InputStream> (input_stream));

		Util::skipWhitespace (std::forward <InputStream> (input_stream));

		if (op == "set")
		{
			this -> readFrom (identifier, std::forward <InputStream> (input_stream));

			Util::skipWhitespace (std::forward <InputStream> (input_stream));
		}
		else if (op == "unset")
		{
			this -> unset (identifier);
		}
		else
		{
			throw Failure::SyntaxError::T ("Unknown operation '" + op + "'\n");
		}
	}

	input_stream . get ();

	this -> validate ();
}
