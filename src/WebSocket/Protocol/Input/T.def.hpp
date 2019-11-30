template <typename Interface>
T <Interface>::T
(
	std::chrono::nanoseconds input_timeout,
	std::chrono::nanoseconds close_timeout,
	uint64_t temp_file_threshhold
)
:	m_input_timeout (input_timeout),
	m_close_timeout (close_timeout),
	m_temp_file_threshhold (temp_file_threshhold)
{
}
