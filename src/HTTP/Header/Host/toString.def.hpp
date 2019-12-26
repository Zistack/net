std::string
T::toString () const
{
	std::string host_string = URI::Authority::Host::toString (this -> host);

	if (this -> port)
	{
		host_string . push_back (':');
		host_string . append (std::to_string (* this -> port));
	}

	return host_string;
}
