template <typename OutputStream>
void
putIdentifier (const std::string & identifier, OutputStream && output_stream)
{
	output_stream.print (identifier);
}
