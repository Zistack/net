T::T (Interface::WatchableInputStream::T <CharType> * input_stream) :
	input_stream (input_stream)
{
	const std::string message_prefix = "IO::Cancellable::InputStream::T\n";

	try
	{
		this -> signal = new Signal::T ();
		this -> epoll = new EPoll::T ();
	}
	catch (Failure::Throwable::T e) throw e.set (message_prefix + e.what ();
}
