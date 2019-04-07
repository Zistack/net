Response::T
T::toResponse (uint64_t temp_file_threshhold) const
{
	HeaderMap::T headers;

	Entity::T error_details (this -> message . size (), temp_file_threshhold);
	error_details . withWriter
	(
		[&] (auto && writer)
		{
			Scope::T writer_scope (writer);

			writer . print (this -> message);
			writer . put ('\n');
		}
	);

	return Response::T
	(
		"HTTP/1.1",
		this -> errorCode (),
		Util::reasonPhrase (this -> errorCode ()),
		headers,
		std::move (error_details)
	);
}
