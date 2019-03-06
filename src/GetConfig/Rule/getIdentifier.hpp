template <typename InputStream>
std::string
getIdentifier (InputStream && input_stream)
{
	return IO::Rule::getClass (
	    std::forward<InputStream> (input_stream), Class::identifier);
}
