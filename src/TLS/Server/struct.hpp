struct T : IO::Interface::ProtocolFactory::T
{
	T (IO::Interface::ProtocolFactory::T & protocol_factory,
	    Context::T & context,
	    uint64_t timeout_ns);

	Protocol::T *
	make () override;

	~T () = default;

	IO::Interface::ProtocolFactory::T & protocol_factory;
	Context::T & context;
	uint64_t timeout_ns;
};
