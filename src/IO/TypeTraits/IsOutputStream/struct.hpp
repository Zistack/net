template <typename InputStream>
struct T
{
	static constexpr const bool value = HasPut::T<InputStream>::value &&
	    HasWrite::T<InputStream>::value && HasPrint::T<InputStream>::value;
};
