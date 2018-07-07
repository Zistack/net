void
T::close (char c)
{
	--this->indentation;
	this->put ('\n');
	output_stream->put (c);
}
