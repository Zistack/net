struct T : IO::Interface::ProtocolFactory::T
{
	T (IO::Interface::ProtocolFactory::T * protocol_factory);

	Protocol::T *
	make () override;

	~T () = default;

	IO::Interface::ProtocolFactory::T * protocol_factory;
};
