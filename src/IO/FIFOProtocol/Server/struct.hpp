template <class RequestType, class ResponseType>
struct T : Interface::ProtocolFactory::T
{
	T (uint64_t input_timeout, uint64_t output_timeout);

	Protocol::T<RequestType, ResponseType> *
	make () = 0;

	~T () = default;

	uint64_t input_timeout;
	uint64_t output_timeout;
};
