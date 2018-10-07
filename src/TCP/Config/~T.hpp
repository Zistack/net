T::~T ()
{
	if (this->hostname) delete[] this->hostname;
	if (this->port) delete[] this->port;
}
