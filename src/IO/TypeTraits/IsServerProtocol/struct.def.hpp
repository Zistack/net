template <typename ServerProtocol, typename>
struct T : std::false_type
{
};

template <typename ServerProtocol>
struct T
<
	ServerProtocol,
	std::enable_if_t
	<
		RETURNS_UNIQUE_PTR <ServerProtocol> &&
			CONNECTION_PROTOCOL_IS_PROTOCOL <ServerProtocol>
	>
> : std::true_type
{
};
