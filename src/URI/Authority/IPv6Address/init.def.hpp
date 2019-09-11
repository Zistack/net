template <typename InputStream>
void
T::init (InputStream && input_stream)
{
	std::vector <uint16_t> head =
		getHead (std::forward <InputStream> (input_stream));

	if (head . size () < 7)
	{
		std::vector <uint16_t> tail =
			getTail (std::forward <InputStream> (input_stream));

		if (head . size () + tail . size () > 7)
		{
			throw Failure::SyntaxError::T ("IPv6 address is too long\n");
		}

		size_t i;
		for (i = 0; i < head . size (); ++ i)
		{
			this -> m_hexadecitets [i] = head [i];
		}

		for (i = 0; i < tail . size (); ++ i)
		{
			this -> m_hexadecitets [8 - tail . size () + i] = tail [i];
		}
	}
	else if (head . size () > 8)
	{
		throw Failure::SyntaxError::T ("IPv6 address is too long\n");
	}
	else
	{
		size_t i;
		for (i = 0; i < head . size (); ++ i)
		{
			this -> m_hexadecitets [i] = head [i];
		}
	}
}
