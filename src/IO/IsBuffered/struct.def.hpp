template <typename Buffered>
struct T
{
	static constexpr bool value =
		(
			IsInputStream::T <Buffered>::value &&
			HasIsReady::T <Buffered>::value
		) ||
		(
			IsOutputStream::T <Buffered>::value &&
			HasFlush::T <Buffered>::value
		);
};
