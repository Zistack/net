template <typename InputStream, typename>
T::T (InputStream && input_stream)
:	Spec::T <T>::T (std::forward <InputStream> (input_stream))
{
	if
	(
		! this -> tcpConfig () . hostname () &&
		! this -> value <Spec::SERVER_NAME> ()
	)
	{
		throw Failure::SemanticError::T
		(
			"Either the Hostname or the Server-Name needs to be set in order "
			"to validate TLS certificates."
		);
	}
}
