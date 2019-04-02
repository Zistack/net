template <typename InputStream>
std::string
T::getFragmentPart (InputStream && input_stream)
{
	std::string fragment_part;

	while (! input_stream . eof ())
	{
		fragment_part . push_back (input_stream . get ());
	}

	return fragment_part;
}
