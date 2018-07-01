struct T : Interface::OutputStream::T
{
	T (Interface::WatchableOutputStream::T * output_stream);

	void
	put (char c) override;

	void
	cancel ();

	~T ();

	Interface::WatchableOutputStream::T * output_stream;
	Signal::T * signal;
	EPoll::T * epoll;
};
