template <typename ServerProtocol>
static constexpr bool RETURNS_UNIQUE_PTR = std::is_same_v
<
	MakeResult::T <ServerProtocol>,
	std::unique_ptr <ConnectionProtocol::T <ServerProtocol>>
>;
