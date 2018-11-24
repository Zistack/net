template <class RequestType, class ResponseType>
struct T : IO::Interface::Server::Protocol::T
{
	T (std::chrono::milliseconds input_timeout,
	    std::chrono::milliseconds output_timeout);

	~T () = default;

	protected:
	virtual std::unique_ptr<IO::Interface::Protocol::T>
	make () override = 0;

	std::chrono::milliseconds input_timeout;
	std::chrono::milliseconds output_timeout;
};
