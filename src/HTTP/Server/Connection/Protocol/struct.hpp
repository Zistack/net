struct T
    : FIFOProtocol::Server::Connection::Protocol::T<Request::T, Response::T>
{
	T (std::chrono::milliseconds input_timeout,
	    std::chrono::milliseconds output_timeout);

	~T () override;

	private:
	Request::T
	readRequest (IO::Blocking::InputStream::T & input_stream) override;

	Response::T
	map (const Request::T & request) override;

	void
	writeResponse (const Response::T & response,
	    IO::Blocking::OutputStream::T & output_stream) override;
};
