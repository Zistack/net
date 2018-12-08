struct T : FIFOPRotocol::Client::Protocol::T<Request::T, Response::T>
{
	T (std::chrono::milliseconds io_timeout,
	    std::chrono::milliseconds round_trip_timeout);

	~T () override;

	private:
	writeRequest (const Request::T & request,
	    IO::Blocking::OutputStream::T & output_stream) override;

	Response::T
	readResponse (IO::Blocking::InputStream::T & input_stream) override;
};
