std::string
encode (char c)
{
	std::string encoded = {'%'};
	encoded.append (IO::Util::charToHex (c));
	return encoded;
}

std::string
encode (const std::string & string)
{
	std::string encoded;

	for (char c : string)
	{
		if (Class::unreserved (c))
		{
			encoded.push_back (c);
		}
		else
		{
			encoded.append (encode (c));
		}
	}

	return encoded;
}
