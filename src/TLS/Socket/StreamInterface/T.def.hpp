template <typename Specialization>
template <typename ... SpecializationArguments, typename>
T <Specialization>::T
(
	int tcp_socket,
	unsigned int flags,
	std::chrono::nanoseconds handshake_timeout,
	size_t config_max_record_size,
	SpecializationArguments && ... specialization_arguments
)
:	Connection::T <Specialization>
	(
		tcp_socket,
		flags,
		handshake_timeout,
		std::forward <SpecializationArguments> (specialization_arguments) ...
	),
	Sender::T <T <Specialization>> (config_max_record_size)
{
}
