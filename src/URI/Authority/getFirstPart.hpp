template <typename InputStream>
std::string
T::getFirstPart (InputStream && input_stream)
{
	return IO::Rule::getNotClass (
	    std::forward<InputStream> (input_stream), '@');
}
