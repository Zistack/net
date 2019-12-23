template <typename OutputStream>
struct T
{
	static constexpr bool value =
		HasPut::T <OutputStream>::value &&
		HasWrite::T <OutputStream>::value &&
		HasPrint::T <OutputStream>::value;
};
