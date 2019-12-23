template <typename ServerProtocol>
static constexpr bool CONNECTION_PROTOCOL_IS_PROTOCOL =
	IsProtocol::T <ConnectionProtocol::T <ServerProtocol>>::value;
