template
<
	template <typename ...> typename PackType,
	typename ... ByteBlocks,
	template <typename ...> typename ResultPackType
>
struct T <PackType <ByteBlocks ...>, ResultPackType>
{
	using Type = ResultPackType
	<
		decltype
		(
			Util::ensureBlocking (std::declval <ByteBlocks> () . reader ())
		) ...
	>;
};
