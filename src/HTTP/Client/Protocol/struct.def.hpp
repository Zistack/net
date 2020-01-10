template <typename Interface>
struct T
:	FIFOProtocolInterface::T <Interface>
{
	T (const Config::T & config);

	using FIFOProtocolInterface::T <Interface>::prime;
	using FIFOProtocolInterface::T <Interface>::run;
	using FIFOProtocolInterface::T <Interface>::cancel;
	using FIFOProtocolInterface::T <Interface>::makeRequest;

	template
	<
		typename UpgradeTarget,
		typename ... RequestArguments,
		typename ... ClientProtocolArguments
	>
	std::variant <std::unique_ptr <UpgradeTarget>, Response::T>
	upgrade
	(
		const std::tuple <RequestArguments ...> & request_arguments,
		const std::tuple <ClientProtocolArguments ...> &
			client_protocol_arguments
	);

	~T () = default;

private:

	using FIFOProtocolInterface::T <Interface>::writeRequest;
	using FIFOProtocolInterface::T <Interface>::readResponse;
	using FIFOProtocolInterface::T <Interface>::writeActive;
	using FIFOProtocolInterface::T <Interface>::writeIdle;
	using FIFOProtocolInterface::T <Interface>::queueActive;
	using FIFOProtocolInterface::T <Interface>::queueIdle;
	using FIFOProtocolInterface::T <Interface>::readActive;
	using FIFOProtocolInterface::T <Interface>::readIdle;
};
