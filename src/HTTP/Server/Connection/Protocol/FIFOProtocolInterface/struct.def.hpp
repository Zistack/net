template <typename Interface, typename ... UpgradeTargets>
struct T
:	FIFOProtocol::Server::Connection::Protocol::T
	<
		T <Interface, UpgradeTargets ...>,
		Request::T,
		Response::T
	>
{
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

protected:

	using UpgradeProtocol = std::variant <std::unique_ptr <UpgradeTargets> ...>;

	template <typename ... UpgradeArguments>
	T
	(
		std::chrono::nanoseconds input_timeout,
		std::chrono::nanoseconds output_timeout,
		const TransferEncoding::Config::T & transfer_encoding_config,
		uint64_t temp_file_threshhold,
		UpgradeArguments && ... upgrade_arguments
	);

	~T () = default;

	// Internal members

	std::mutex m_upgrade_mutex;
	UpgradeFactory::T <UpgradeTargets ...> m_upgrade_factory;
	std::optional <UpgradeProtocol> m_upgrade_protocol;

private:

	// Access to external members

	const Interface &
	interface () const;

	Interface &
	interface ();

	// Given members

	std::chrono::nanoseconds m_input_timeout;
	std::chrono::nanoseconds m_output_timeout;
	const TransferEncoding::Config::T & m_transfer_encoding_config;
	uint64_t m_temp_file_threshhold;
};
