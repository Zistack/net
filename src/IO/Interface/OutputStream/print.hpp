void
T::print (std::string message)
{
	this->write ((char *) message.data (), message.size ());
}
