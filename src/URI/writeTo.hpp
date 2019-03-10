template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream)
{
	if (this->scheme)
	{
		output_stream.print (this->scheme.stdString ());
		output_stream.put (':');
	}

	if (this->authority)
	{
		output_stream.print ("//");
		this->authority->writeTo (std::forward<OutputStream> (output_stream));
	}

	this->path.writeTo (std::forward<OutputStream> (output_stream));

	if (this->query)
	{
		output_stream.put ('?');
		output_stream.print (Util::encode (this->query.stdString ()));
	}

	if (this->fragment)
	{
		output_stream.put ('#');
		output_stream.print (Util::encode (this->fragment.stdString ()));
	}
}
