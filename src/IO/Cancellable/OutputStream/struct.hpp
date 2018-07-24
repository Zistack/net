struct T : Interface::OutputStream::T
{
	T (Interface::WatchableOutputStream::T * output_stream, Signal::T * signal);

	void
	put (char c) override;

	~T () = default;

	Interface::WatchableOutputStream::T * output_stream;
	Signal::T * signal;
};
