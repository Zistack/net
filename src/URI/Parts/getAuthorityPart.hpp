template <typename InputStream>
std::string
T::getAuthorityPart (InputStream && input_stream)
{
	return IO::Rule::getNotClass (
	    std::forward<InputStream> (input_stream), Class::secondDelimiter);
}
