template <typename Specialization>
struct T
:	Connection::T <T <Specialization>, Specialization>,
	Reciever::T <T <Specialization>>,
	Sender::T <T <Specialization>>
{
	using Reciever::T <T <Specialization>>::reciever;
	using Sender::T <T <Specialization>>::sender;

	std::mutex write_mutex;

protected:

	template
	<
		typename ... SpecializationArguments,
		typename = std::enable_if_t
		<
			std::is_constructible_v
			<
				Specialization,
				gnutls_session_t,
				SpecializationArguments ...
			>
		>
	>
	T
	(
		int tcp_socket,
		unsigned int flags,
		std::chrono::nanoseconds handshake_timeout,
		size_t config_max_record_size,
		SpecializationArguments && ... specialization_arguments
	);

	~T () = default;
};
