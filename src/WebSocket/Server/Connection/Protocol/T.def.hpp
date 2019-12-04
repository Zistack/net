template <typename Interface, bool upgrade_required>
T <Interface, upgrade_required>::T
(
	const HTTP::Request::T & request,
	const ResponseFactory & response_factory,
	const Config::T & config
)
:	WebSocket::Protocol::T <Interface> (config)
{
}
