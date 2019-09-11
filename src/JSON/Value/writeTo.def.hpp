template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream, size_t indentation)
{
	std::visit
	(
		[&] (auto && contents)
		{
			contents . writeTo
			(
				std::forward <OutputStream> (output_stream),
				indentation
			);
		},
		this -> m_contents
	);
}
