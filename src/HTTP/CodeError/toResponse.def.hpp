Response::T
T::toResponse (uint64_t temp_file_threshhold) const
{
	Entity::T error_details (this -> m_message . size (), temp_file_threshhold);
	error_details . withWriter
	(
		[&] (auto && writer)
		{
			using OutputStream = decltype (writer);

			if constexpr (IO::TypeTraits::IsBuffered::T <OutputStream>::value)
			{
				Scope::T writer_scope (writer);

				writer . print (this -> m_message);
				writer . put ('\n');
			}
			else
			{
				writer . print (this -> m_message);
				writer . put ('\n');
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
