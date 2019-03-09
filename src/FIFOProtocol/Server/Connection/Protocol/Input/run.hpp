template <typename Request, typename Response, typename Interface>
template <typename InputStream>
void
T<Request, Response, Interface>::run (InputStream && input_stream)
{
	{
		SuppressingScope::T<Shutdown::Signal::T> input_shutdown_scope (
		    std::move (this->input_shutdown_scope));

		Thread::Nursery::T nursery (this->exception_store);

		::Protocol::eventLoop (this->exception_store,
		    std::forward<InputStream> (input_stream),
		    this->input_shutdown_signal,
		    &T::event<InputStream>,
		    this,
		    std::forward<InputStream> (input_stream),
		    nursery);
	}

	exception_store.pop ();
}
