template <typename Protocol, typename Dispatcher>
template <typename ... Arguments>
T <Protocol, Dispatcher>::T
(
	std::chrono::milliseconds input_timeout,
	std::chrono::milliseconds close_timeout,
	uint64_t temp_file_threshhold,
	Arguments && ... arguments
)
:	m_input_timeout (input_timeout),
	m_close_timeout (close_timeout),
	m_temp_file_threshhold (temp_file_threshhold),
	m_dispatcher (std::forward <Arguments> (arguments) ...)
{
}
