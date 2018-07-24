struct T : Interface::InputStream::T
{
	T (Interface::WatchableInputStream::T * input_stream, Signal::T * signal);

	char
	get () override;

	~T () = default;

	Interface::WatchableInputStream::T * input_stream;
	Signal::T * signal;
};
