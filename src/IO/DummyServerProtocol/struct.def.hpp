struct T
{
	std::unique_ptr <DummyProtocol::T>
	make ();
};

static_assert (IsServerProtocol::T <T>::value);
