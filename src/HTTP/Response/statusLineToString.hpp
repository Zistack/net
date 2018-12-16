std::string
T::statusLineToString () const
{
	std::string status_line;

	status_line.append (this->version);

	status_line.push_back (' ');

	status_line.append (std::to_string (this->status_code));

	status_line.push_back (' ');

	status_line.append (this->reason_phrase);

	status_line.append ("\r\n");

	return status_line;
}
