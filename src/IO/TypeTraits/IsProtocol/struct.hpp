template <typename Protocol>
struct T
{
	static constexpr const bool value = HasPrime::T<Protocol>::value &&
	    HasRun::T<Protocol>::value &&
	    Failure::TypeTraits::IsCancellable::T<Protocol>::value;
};
