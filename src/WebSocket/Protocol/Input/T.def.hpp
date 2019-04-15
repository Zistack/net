template <typename Dispatcher>
template <typename ... Arguments>
T <Dispatcher>::T
(
	std::chrono::milliseconds input_timeout,
	std::chrono::milliseconds close_timeout,
	uint64_t temp_file_threshhold,
	Output::T & output,
	Arguments && ... arguments
)
:	input_timeout (input_timeout),
	close_timeout (close_timeout),
	temp_file_threshhold (temp_file_threshhold),
	output (output),
	dispatcher (std::forward <Arguments> (arguments) ...)
{
}
