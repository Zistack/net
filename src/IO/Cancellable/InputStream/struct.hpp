struct T : Interface::InputStream::T
{
	T (Interface::WatchableInputStream::T * input_stream);

	char
	get () override;

	void
	cancel ();

	~T ();

	Interface::WatchableInputStream::T * input_stream;
	Signal::T * signal;
	EPoll::T * epoll;
};
