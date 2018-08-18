void
T::runOutputDump ()
{
	const std::string message_prefix = "TLS::Adapter::runOutputDump\n";

	try
	{
		while (true)
		{
			{
				Thread::Timeout::T (this->timeout_ns,
				    [&]() { this->output_timeout_signal->send (); });

				IO::Util::wait (this->protocol_to_socket->input_stream,
				    *this->output_timeout_signal);

				size_t num_bytes = this->protocol_to_socket->input_stream.read (
				    this->output_buffer, T::BUF_SIZE);

				this->ssl.write (this->output_buffer,
				    (int) num_bytes,
				    *this->output_timeout_signal);
			}
			this->output_timeout_signal->recieve ();
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
