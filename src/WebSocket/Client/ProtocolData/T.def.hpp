T::T ()
:	client_key_base64
	(
		Crypto::Base64::encodedLength
		(
			std::tuple_size <HandshakeKey::T>::value
		),
		'\0'
	)
{
}
