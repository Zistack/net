template <typename Protocol>
void
T <Protocol>::run ()
{
	Failure::ExceptionStore::T exception_store;

	try
	{
		Socket::T client_socket (this -> m_config, this -> m_ciphers);

		exception_store . tryStore
		(
			[&] ()
			{
				this -> m_protocol . run
				(
					client_socket . reciever (),
					client_socket . sender ()
				);
			}
		);
	}
	catch (...)
	{
		exception_store . store (std::current_exception ());
	}

	exception_store . poll ();
}
