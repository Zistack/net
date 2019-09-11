template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream, size_t indentation) const
{
	IO::Util::indent
	(
		std::forward <OutputStream> (output_stream),
		indentation
	);

	output_stream . put ('"');

	for (char c : this -> value)
	{
		switch (c)
		{
		case '"':

			output_stream . print ("\\\"");
			break;

		case '\\':

			output_stream . print ("\\\\");
			break;

		case '\x08':

			output_stream . print ("\\b");
			break;

		case '\x09':

			output_stream . print ("\\t");
			break;

		case '\x0A':

			output_stream . print ("\\n");
			break;

		case '\x0C':

			output_stream . print ("\\f");
			break;

		case '\x0D':

			output_stream . print ("\\r");
			break;

		default:

			if (Class::control (c))
			{
				Rule::putEscape
				(
					std::forward <OutputStream> (output_stream),
					(char32_t) c
				);
			}
			else output_stream . put (c);
		}
	}

	output_stream . put ('"');
}
