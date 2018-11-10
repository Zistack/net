template <class RequestType, class ResponseType>
struct T : IO::Interface::Server::Protocol::T
{
	T (std::chrono::milliseconds input_timeout,
	    std::chrono::milliseconds output_timeout);

	virtual std::unique_ptr<IO::Interface::Protocol::T>
	make () override = 0;

	~T () = default;

	std::chrono::milliseconds input_timeout;
	std::chrono::milliseconds output_timeout;
};
