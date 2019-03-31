template <typename ServerProtocol>
static constexpr const bool RETURNS_UNIQUE_PTR = std::is_same_v
<
	MakeResult::T <ServerProtocol>,
	std::unique_ptr <ConnectionProtocol::T <ServerProtocol>>
>;
