template <typename CharType>
struct T : Interface::InputStream::T <CharType>
{
	T (Interface::WatchableInputStream::T <CharType> * input_stream);

	CharType
	get () override;

	void
	cancel ();

	~T ();

	Interface::WatchableInputStream::T <CharType> * input_stream;
	Signal::T * signal;
	EPoll::T * epoll;
};
