std::string
T::toString () const
{
	size_t max_position = 0;
	size_t max_size = 0;

	size_t current_position = 0;
	size_t current_size = 0;

	size_t i;
	for (i = 0; i < 8; ++ i)
	{
		if (this -> m_hexadecitets [i] == 0)
		{
			if (current_position + current_size == i)
			{
				++current_size;
			}
			else
			{
				current_position = i;
				current_size = 1;
			}
		}
		else
		{
			if (current_size > max_size)
			{
				max_position = current_position;
				max_size = current_size;
			}
		}
	}
	if (current_size > max_size)
	{
		max_position = current_position;
		max_size = current_size;
	}

	std::string address_string;

	for (i = 0; i < 8;)
	{
		if (i == max_position && max_size > 1)
		{
			if (i == 0) address_string . push_back (':');
			address_string . push_back (':');
			i += max_size;
		}
		else
		{
			address_string . append
			(
				hexadecitetToString (this -> m_hexadecitets [i])
			);
			++ i;
			if (i < 8) address_string . push_back (':');
		}
	}

	return address_string;
}
