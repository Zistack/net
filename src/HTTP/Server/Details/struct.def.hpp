template <typename Responder, typename ... UpgradeTargets>
struct T
{
	using UpgradeProtocol = std::variant <std::unique_ptr <UpgradeTargets> ...>;

	template <typename ... ResponderArguments, typename ... UpgradeArguments>
	T
	(
		std::chrono::nanoseconds input_timeout,
		std::chrono::nanoseconds output_timeout,
		const TransferEncoding::Config::T & transfer_encoding_config,
		uint64_t temp_file_threshhold,
		const std::tuple <ResponderArguments ...> & responder_arguments,
		UpgradeArguments && ... upgrade_arguments
	);

	template <typename InputStream>
	Request::T
	readRequest (InputStream && input_stream) const;

	Response::T
	map (const Request::T & request);

	template <typename OutputStream>
	void
	writeResponse
	(
		const Response::T & response,
		OutputStream && output_stream
	) const;

	~T () = default;

private:

	// Given members

	std::chrono::nanoseconds m_input_timeout;
	std::chrono::nanoseconds m_output_timeout;
	const TransferEncoding::Config::T & m_transfer_encoding_config;
	uint64_t m_temp_file_threshhold;

	// Internal members

	Responder m_responder;

	std::mutex m_upgrade_mutex;
	UpgradeFactory::T <UpgradeTargets ...> m_upgrade_factory;
	std::optional <UpgradeProtocol> m_upgrade_protocol;

	friend Connection::Protocol::T <Responder, UpgradeTargets ...>;
};
