template <typename Responder, typename ... UpgradeTargets>
using T = FIFOProtocol::Server::Connection::Protocol::T
<
	Request::T,
	Response::T,
	Details::T <Responder, UpgradeTargets ...>
>;
