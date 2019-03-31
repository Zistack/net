template <typename Rule>
auto
parseFile
(
	const std::string & filename,
	std::chrono::milliseconds timeout,
	Rule && rule
)
{
	File::T file (filename, "r");
	Blocking::InputStream::T input_stream (file.reader ());

	Thread::Timer::T timer
	(
		timeout,
		& decltype (input_stream)::cancel,
		& input_stream
	);

	return consume (input_stream, std::forward <Rule> (rule));
}
