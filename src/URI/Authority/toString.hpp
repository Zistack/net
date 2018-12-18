std::string
T::toString () const
{
	std::string authority_string;

	if (this->user_info)
	{
		authority_string.append (Util::encode ((std::string) this->user_info));
		authority_string.push_back ('@');
	}

	authority_string.append (this->host->toString ());

	if (this->port)
	{
		authority_string.push_back (':');
		authority_string.append (std::to_string (this->port.value ()));
	}

	return authority_string;
}
