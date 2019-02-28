void
T::run ()
{
	Shutdown::Signal::T input_shutdown_signal;
	Failure::CancelScope::T output_cancel_scope;

	// We might need a scope for the shutdown signal.

	{
		this->nursery->add (
		    input_shutdown_signal, &T::input, this, input_shutdown_signal);

		this->nursery->run (
		    output_cancel_scope, &T::output, this, output_cancel_scope);

		std::unique_lock<decltype (this->nursery_mutex)> nursery_lock (
		    this->nursery_mutex);
		std::unique_ptr<Thread::Nursery::T> nursery (std::move (this->nursery));
	}

	{
		std::unique_lock<decltype (close_mutex)> close_lock (this->close_mutex);
		this->status_code = 0;
		this->reason.reset ();
	}

	this->nonblocking_input_stream = nullptr;
	this->nonblocking_output_stream = nullptr;

	this->exception_store.pop ();
}
