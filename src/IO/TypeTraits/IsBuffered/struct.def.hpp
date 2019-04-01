template <typename Buffered>
struct T
{
	static constexpr const bool value =
		(
			IsInputStream::T <Buffered>::value &&
			HasIsReady::T <Buffered>::value
		) ||
		(
			IsOutputStream::T <Buffered>::value &&
			IsScopable::T <Buffered>::value
		);
};
