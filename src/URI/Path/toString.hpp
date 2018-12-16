std::string
T::toString () const
{
	std::string path_string;

	if (absolute)
	{
		path_string.push_back ('/');
	}

	for (std::string segment : this->segments)
	{
		path_string.append (Util::encode (segment));
		path_string.push_back ('/');
	}

	path_string.pop_back ();

	return path_string;
}
