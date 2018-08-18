void
T::event ()
{
	const std::string message_prefix = "TLS::Adapter::event\n";

	try
	{
		this->exception_store.poll ();

		{
			Thread::Timeout::T (this->timeout_ns,
			    [&]() { this->input_timeout_signal->send (); });

			do
			{
				size_t num_bytes = (size_t) this->ssl.read (this->input_buffer,
				    T::BUF_SIZE,
				    *this->input_timeout_signal);

				this->protocol_output_stream->write (
				    this->input_buffer, num_bytes);
			} while (this->ssl.hasBufferedBytes ());
		}
		this->input_timeout_signal->recieve ();
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
