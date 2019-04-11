template <typename InputStream>
T::T (InputStream && input_stream)
{
	IO::Util::expect (std::forward <InputStream> (input_stream), "null");
}
