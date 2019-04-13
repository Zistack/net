template
<
	template <typename ...> typename ByteBlockPackContainer,
	typename ... ByteBlocks,
	template <typename ...> typename ResultPackContainer
>
struct T <ByteBlockPackContainer <ByteBlocks ...>, ResultPackContainer>
{
	using Type = ResultPackContainer
	<
		decltype
		(
			Util::ensureBlocking (std::declval <ByteBlocks> () . reader ())
		) ...
	>;
};
