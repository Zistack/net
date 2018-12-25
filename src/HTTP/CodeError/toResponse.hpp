Response::T
T::toResponse () const noexcept
{
	HeaderMap::T headers;

	std::unique_ptr<Entity::T> error_details (new BlockingEntity::T (
	    std::make_unique<IO::String::T> (this->what ())));

	return Response::T ("HTTP/1.1",
	    this->errorCode (),
	    Util::reasonPhrase (this->errorCode ()),
	    headers,
	    std::move (error_details));
}
