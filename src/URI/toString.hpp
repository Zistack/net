std::string
T::toString () const
{
	std::string uri_string;

	if (this->scheme)
	{
		uri_string.append ((std::string) this->scheme);
		uri_string.push_back (':');
	}

	if (this->authority)
	{
		uri_string.append ("//");
		uri_string.append (this->authority->toString ());
	}

	uri_string.append (this->path.toString ());

	if (this->query)
	{
		uri_string.push_back ('?');
		uri_string.append (Util::encode ((std::string) this->query));
	}

	if (this->fragment)
	{
		uri_string.push_back ('#');
		uri_string.append (Util::encode ((std::string) this->fragment));
	}

	return uri_string;
}
