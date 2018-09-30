template <class RequestType, class ResponseType>
struct T : IO::Interface::ProtocolFactory::T
{
	T (std::chrono::milliseconds input_timeout,
	    std::chrono::milliseconds output_timeout);

	virtual Protocol::T<RequestType, ResponseType> *
	make () override = 0;

	~T () = default;

	std::chrono::milliseconds input_timeout;
	std::chrono::milliseconds output_timeout;
};
