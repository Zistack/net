template <typename Watchable>
struct T
{
	static constexpr const bool value =
		HasEvents::T <Watchable>::value &&
		HasFileDescriptor::T <Watchable>::value;
};
