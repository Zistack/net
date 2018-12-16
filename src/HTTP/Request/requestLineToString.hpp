std::string
T::requestLineToString () const
{
	std::string request_line;

	request_line.append (this->method);

	request_line.push_back (' ');

	request_line.append (uri.toString ());

	request_line.push_back (' ');

	request_line.append (this->version);

	request_line.append ("\r\n");

	return request_line;
}
