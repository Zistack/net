template <typename Response, typename Interface>
template <typename InputStream>
void
T<Response, Interface>::run (InputStream && input_stream)
{
	{
		SuppressingScope::T<Shutdown::Signal::T> input_shutdown_scope (
		    std::move (this->input_shutdown_scope));

		Scope::T<decltype (this->response_queue)> response_scope (
		    std::move (this->response_scope));

		::Protocol::eventLoop (this->exception_store,
		    std::forward<InputStream> (input_stream),
		    this->input_shutdown_signal,
		    &T::event<InputStream>,
		    this,
		    std::forward<InputStream> (input_stream));
	}

	this->exception_store.pop ();
}
