void
T::print (const std::string & message)
{
	this->write ((char *) message.data (), message.size ());
}
