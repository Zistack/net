std::vector<uint16_t>
T::getTail (IO::Interface::PeekableInputStream::T & input_stream)
{
	std::vector<uint16_t> tail;

	while (true)
	{
		std::string chunk = IO::Rule::getClass (input_stream, IO::Class::hex);

		if (IO::Util::test (input_stream, ':'))
		{
			input_stream.get ();

			if (chunk.size () == 0)
			{
				throw Failure::SyntaxError::T (
				    "An IPv6 address may not contain more than one empty "
				    "group\n");
			}
			else if (chunk.size () > 4)
			{
				throw Failure::SyntaxError::T (
				    "A hexadecitet may only contain up to 4 digits\n");
			}

			tail.push_back ((uint16_t) std::stoul (chunk, NULL, 16));
		}
		else if (IO::Util::test (input_stream, '.'))
		{
			if (chunk.size () == 0)
			{
				throw Failure::SyntaxError::T ("Expected numeric value\n");
			}

			uint64_t first = IO::Util::toUInt (chunk);
			if (first > 255)
			{
				throw Failure::SyntaxError::T (
				    "IPv4 octet must be less than 256\n");
			}

			input_stream.get ();

			uint64_t second = IO::Rule::getUInt (input_stream);

			if (second > 255)
			{
				throw Failure::SyntaxError::T (
				    "IPv4 octet must be less than 256\n");
			}

			IO::Util::expect (input_stream, '.');
			uint64_t third = IO::Rule::getUInt (input_stream);

			if (third > 255)
			{
				throw Failure::SyntaxError::T (
				    "IPv4 octet must be less than 256\n");
			}

			IO::Util::expect (input_stream, '.');
			uint64_t fourth = IO::Rule::getUInt (input_stream);

			if (fourth > 255)
			{
				throw Failure::SyntaxError::T (
				    "IPv4 octet must be less than 256\n");
			}

			tail.push_back ((uint16_t) ((first << 8) | second));
			tail.push_back ((uint16_t) ((third << 8) | fourth));

			return tail;
		}
		else
		{
			if (chunk.size () == 0)
			{
				if (tail.size () == 0) return tail;

				throw Failure::SyntaxError::T (
				    "A hexadecitet must contain at least 1 digit\n");
			}
			else if (chunk.size () > 4)
			{
				throw Failure::SyntaxError::T (
				    "A hexadecitet may only contain up to 4 digits\n");
			}

			tail.push_back ((uint16_t) std::stoul (chunk, NULL, 16));

			return tail;
		}
	}
}
