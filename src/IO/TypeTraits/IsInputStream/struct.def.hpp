template <typename InputStream>
struct T
{
	static constexpr bool value =
		HasGet::T <InputStream>::value &&
		HasPeek::T <InputStream>::value &&
		HasEOF::T <InputStream>::value;
};
