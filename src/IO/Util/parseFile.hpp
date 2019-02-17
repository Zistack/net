template <typename Rule>
typename std::invoke_result<Rule, Interface::PeekableInputStream::T &>::type
parseFile (const std::string & filename,
    std::chrono::milliseconds timeout,
    Rule && rule)
{
	File::T file (filename, "r");
	CancelSignal::T timeout_signal;
	Blocking::InputStream::T input_stream (file.inputStream (), timeout_signal);

	Thread::Timer::T timer (timeout, &CancelSignal::T::cancel, &timeout_signal);

	return consume (input_stream, std::forward<Rule> (rule));
}
