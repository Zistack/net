struct T
{
	std::unique_ptr <Protocol::T>
	make ();
};

static_assert (IsServerProtocol::T <T>::value);
