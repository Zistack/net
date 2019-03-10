template <typename InputStream>
std::string
T::getQueryPart (InputStream && input_stream)
{
	return IO::Rule::getNotClass (
	    std::forward<InputStream> (input_stream), Class::fourthDelimiter);
}
