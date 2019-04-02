template <typename InputStream>
std::vector <uint16_t>
T::getHead (InputStream && input_stream)
{
	std::vector <uint16_t> head;

	if (IO::Util::test (std::forward <InputStream> (input_stream), ':'))
	{
		IO::Util::expect (std::forward <InputStream> (input_stream), "::");
		return head;
	}

	while (true)
	{
		std::string chunk = IO::Rule::getClass
		(
			std::forward <InputStream> (input_stream),
			IO::Class::hex
		);

		if (IO::Util::test (std::forward <InputStream> (input_stream), ':'))
		{
			input_stream . get ();

			if (chunk . size () == 0)
			{
				return head;
			}
			else if (chunk . size () > 4)
			{
				throw Failure::SyntaxError::T
				(
					"A hexadecitet may only contain up to 4 digits\n"
				);
			}

			head . push_back ((uint16_t) std::stoul (chunk, NULL, 16));
		}
		else if
		(
			IO::Util::test (std::forward <InputStream> (input_stream), '.')
		)
		{
			if (chunk . size () == 0)
			{
				throw Failure::SyntaxError::T ("Expected numeric value\n");
			}

			uint64_t first = IO::Util::toUInt (chunk);
			if (first > 255)
			{
				throw Failure::SyntaxError::T
				(
					"IPv4 octet must be less than 256\n"
				);
			}

			input_stream . get ();

			uint64_t second = IO::Rule::getUInt
			(
				std::forward <InputStream> (input_stream)
			);

			if (second > 255)
			{
				throw Failure::SyntaxError::T
				(
					"IPv4 octet must be less than 256\n"
				);
			}

			IO::Util::expect (std::forward <InputStream> (input_stream), '.');
			uint64_t third = IO::Rule::getUInt
			(
				std::forward <InputStream> (input_stream)
			);

			if (third > 255)
			{
				throw Failure::SyntaxError::T
				(
					"IPv4 octet must be less than 256\n"
				);
			}

			IO::Util::expect (std::forward <InputStream> (input_stream), '.');
			uint64_t fourth = IO::Rule::getUInt
			(
				std::forward <InputStream> (input_stream)
			);

			if (fourth > 255)
			{
				throw Failure::SyntaxError::T
				(
					"IPv4 octet must be less than 256\n"
				);
			}

			head . push_back ((uint16_t) ((first << 8) | second));
			head . push_back ((uint16_t) ((third << 8) | fourth));

			if (head . size () < 8)
			{
				throw Failure::SyntaxError::T ("IPv6 address is too short\n");
			}
			else if (head . size () > 8)
			{
				throw Failure::SyntaxError::T ("IPv6 address is too long\n");
			}

			return head;
		}
		else
		{
			if (chunk . size () == 0)
			{
				throw Failure::SyntaxError::T
				(
					"Expected empty group to be terminated with a colon ':'\n"
				);
			}
			if (chunk . size () > 4)
			{
				throw Failure::SyntaxError::T
				(
					"A hexadecitet may only contain up to 4 digits\n"
				);
			}

			head . push_back ((uint16_t) std::stoul (chunk, NULL, 16));

			return head;
		}
	}
}
