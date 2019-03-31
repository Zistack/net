template <typename ServerProtocol>
using T = std::remove_reference_t
<
	decltype (* std::declval <MakeResult::T <ServerProtocol>> ())
>;
