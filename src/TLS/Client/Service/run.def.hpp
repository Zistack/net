template <typename Protocol>
void
T <Protocol>::run ()
{
	Socket::T client_socket (this -> m_config);

	this -> m_protocol . run
	(
		client_socket . reciever (),
		client_socket . sender ()
	);
}
