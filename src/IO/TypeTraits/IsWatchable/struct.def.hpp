template <typename Watchable>
struct T
{
	static constexpr bool value =
		HasEvents::T <Watchable>::value &&
		HasFileDescriptor::T <Watchable>::value;
};
