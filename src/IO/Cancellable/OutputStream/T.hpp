T::T (Interface::WatchableOutputStream::T <CharType> * output_stream) :
	output_stream (output_stream)
{
	const std::string message_prefix = "IO::Cancellable::OutputStream::T\n";

	try
	{
		signal = new Signal::T ();
		epoll = new EPoll::T ();
	}
	catch (Failure::Throwable::T e) throw e.set (message_prefix + e.what ());
}
