template <typename CharType>
struct T : Interface::OutputStream::T <CharType>
{
	T (Interface::WatchableOutputStream::T <CharType> * output_stream);

	void put (CharType c) override;

	void
	cancel ();

	~T ();

	Interface::WatchableOutputStream::T <CharType> * output_stream;
	Signal::T * signal;
	EPoll::T * epoll;
};
