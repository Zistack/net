std::string
T::head () const
{
	std::string head;
	IO::String::Writer::T output_stream (head);
	this -> putHead (output_stream);

	return head;
}
