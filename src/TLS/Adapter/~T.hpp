T::~T ()
{
	delete this->socket_to_protocol;
	delete this->input_timeout_signal;
	delete this->protocol_output_stream;
	delete this->protocol_to_socket;
	delete this->output_timeout_signal;
	delete this->shutdown_signal;
}
