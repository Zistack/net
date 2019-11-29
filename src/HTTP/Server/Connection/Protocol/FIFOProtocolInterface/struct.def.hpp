template <typename Interface, typename ... UpgradeTargets>
struct T
:	FIFOProtocol::Server::Connection::Protocol::T
	<
		T <Interface, UpgradeTargets ...>,
		Request::T,
		Response::T
	>
{
protected:

	using UpgradeProtocol = std::variant <std::unique_ptr <UpgradeTargets> ...>;

	template <typename ... UpgradeArguments>
	T (const Config::T & config, UpgradeArguments && ... upgrade_arguments);

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

protected:

	// Internal members

	std::mutex m_upgrade_mutex;
	UpgradeFactory::T <UpgradeTargets ...> m_upgrade_factory;
	std::optional <UpgradeProtocol> m_upgrade_protocol;
};
