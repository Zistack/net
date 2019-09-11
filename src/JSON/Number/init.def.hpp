template <typename InputStream>
void
T::init (InputStream && input_stream)
{
	char c;

	try
	{
		this -> m_base = Rule::getBase
		(
			std::forward <InputStream> (input_stream)
		);

		if (input_stream . eof ()) return;

		c = input_stream . peek ();

		if (c == '.')
		{
			input_stream . get ();
			goto mantissa;
		}

		if (c == 'E' || c == 'e')
		{
			input_stream . get ();
			goto exponent;
		}

		return;

	mantissa:

		this -> m_mantissa = Rule::getMantissa
		(
			std::forward <InputStream> (input_stream)
		);

		if (input_stream . eof ()) return;

		c = input_stream . peek ();

		if (c == 'E' || c == 'e')
		{
			input_stream . get ();
			goto exponent;
		}

		return;

	exponent:

		this -> m_exponent = Rule::getExponent
		(
			std::forward <InputStream> (input_stream)
		);

		return;
	}
	catch (Failure::EndOfResource::T e)
	{
		throw Failure::SyntaxError::T (IO::Message::unexpectedEOF ());
	}
}
