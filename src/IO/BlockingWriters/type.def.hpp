template
<
	typename ByteBlockPack,
	template <typename ...> typename ResultPackContainer = std::tuple
>
using T = Implementation::T <ByteBlockPack, ResultPackContainer>;
