template <std::function <Response::T * (Request::T *)> handle>
struct T : IO::ProtocolFactory::T
{
	T (UTI::T uri, IO::Interface::OutputStream <char> * log);

	Connection::T <handle> * make ();

	~T () = default;

	UTI::T uri;
	IO::Interface::OutputStream <char> * log;
};
