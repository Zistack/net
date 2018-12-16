T &
T::operator= (const T & other)
{
	this->user_info = other.user_info;
	this->host = other.host->clone ();
	this->port = other.port;

	return *this;
}
