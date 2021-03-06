template <typename Protocol>
struct T
{
	static constexpr bool value =
		HasPrime::T <Protocol>::value &&
		HasRun::T <Protocol>::value &&
		Failure::IsCancellable::T <Protocol>::value;
};
