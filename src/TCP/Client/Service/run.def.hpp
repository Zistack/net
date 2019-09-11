template <typename Protocol>
void
T <Protocol>::run ()
{
	Socket::T client_socket (this -> m_config);

	IO::Blocking::InputStream::T input_stream (client_socket . reciever ());
	IO::Blocking::OutputStream::T output_stream (client_socket . sender ());

	this -> m_protocol . run (input_stream, output_stream);
}
