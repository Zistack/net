void
T::open (char c)
{
	output_stream->put (c);
	++this->indentation;
	this->put ('\n');
}
