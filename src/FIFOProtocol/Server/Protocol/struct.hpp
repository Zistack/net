template <class RequestType, class ResponseType>
struct T : IO::Interface::Server::Protocol::T
{
	T () = default;

	~T () = default;

	protected:
	virtual std::unique_ptr<IO::Interface::Protocol::T>
	make () override = 0;
};
