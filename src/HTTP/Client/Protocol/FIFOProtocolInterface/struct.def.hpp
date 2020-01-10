template <typename Interface>
struct T
:	FIFOProtocol::Client::Protocol::T <T <Interface>, Request::T, Response::T>
{
	template <typename OutputStream>
	void
	writeRequest
	(
		const Request::T & request,
		OutputStream && output_stream
	) const;

	template <typename InputStream>
	Response::T
	readResponse (InputStream && input_stream) const;

	template
	<
		typename ProxyInterface = Interface,
		typename = std::enable_if_t
		<
			FIFOProtocol::HooksLoadEvents::T <ProxyInterface>::value
		>
	>
	void
	writeActive ();

	template
	<
		typename ProxyInterface = Interface,
		typename = std::enable_if_t
		<
			FIFOProtocol::HooksLoadEvents::T <ProxyInterface>::value
		>
	>
	void
	writeIdle ();

	template
	<
		typename ProxyInterface = Interface,
		typename = std::enable_if_t
		<
			FIFOProtocol::HooksLoadEvents::T <ProxyInterface>::value
		>
	>
	void
	queueActive ();

	template
	<
		typename ProxyInterface = Interface,
		typename = std::enable_if_t
		<
			FIFOProtocol::HooksLoadEvents::T <ProxyInterface>::value
		>
	>
	void
	queueIdle ();

	template
	<
		typename ProxyInterface = Interface,
		typename = std::enable_if_t
		<
			FIFOProtocol::HooksLoadEvents::T <ProxyInterface>::value
		>
	>
	void
	readActive ();

	template
	<
		typename ProxyInterface = Interface,
		typename = std::enable_if_t
		<
			FIFOProtocol::HooksLoadEvents::T <ProxyInterface>::value
		>
	>
	void
	readIdle ();

protected:

	T
	(
		std::chrono::nanoseconds input_timeout,
		std::chrono::nanoseconds output_timeout,
		std::chrono::nanoseconds round_trip_timeout,
		const TransferEncoding::Config::T & transfer_encoding_config,
		uint64_t temp_file_threshhold
	);

	~T () = default;

private:

	template
	<
		typename ProxyInterface = Interface,
		typename = std::enable_if_t
		<
			FIFOProtocol::HooksLoadEvents::T <ProxyInterface>::value
		>
	>
	const ProxyInterface &
	interface () const;

	template
	<
		typename ProxyInterface = Interface,
		typename = std::enable_if_t
		<
			FIFOProtocol::HooksLoadEvents::T <ProxyInterface>::value
		>
	>
	ProxyInterface &
	interface ();

	std::chrono::nanoseconds m_input_timeout;
	std::chrono::nanoseconds m_output_timeout;
	TransferEncoding::Config::T m_transfer_encoding_config;
	uint64_t m_temp_file_threshhold;
};
