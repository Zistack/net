template <typename Interface>
T <Interface>::T
(
	std::chrono::nanoseconds input_timeout,
	std::chrono::nanoseconds output_timeout,
	std::chrono::nanoseconds close_timeout,
	uint64_t chunk_size,
	uint64_t temp_file_threshhold
)
:	Input::T <T <Interface>>
	(
		input_timeout,
		output_timeout,
		temp_file_threshhold
	),
	Output::T (output_timeout, chunk_size)
{
}
