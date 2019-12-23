Response::T
T::toResponse (uint64_t temp_file_threshhold) const
{
	Entity::T error_details (this -> m_message . size (), temp_file_threshhold);
	error_details . withWriter
	(
		[&] (auto && writer)
		{
			using OutputStream = decltype (writer);

			writer . print (this -> m_message);
			writer . put ('\n');

			if constexpr (IO::IsBuffered::T <OutputStream>::value)
			{
				writer . flush ();
			}
		}
	);

	return Response::T
	(
		"HTTP/1.1",
		this -> errorCode (),
		Util::reasonPhrase (this -> errorCode ()),
		this -> m_headers,
		std::move (error_details)
	);
}
