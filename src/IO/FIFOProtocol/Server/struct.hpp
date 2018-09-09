template <class RequestType, class ResponseType>
struct T : Interface::ProtocolFactory::T
{
	T (std::chrono::milliseconds input_timeout,
	    std::chrono::milliseconds output_timeout);

	Protocol::T<RequestType, ResponseType> *
	make () = 0;

	~T () = default;

	std::chrono::milliseconds input_timeout;
	std::chrono::milliseconds output_timeout;
};
