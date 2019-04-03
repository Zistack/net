template <typename Stream>
auto
ensureBlocking (Stream && stream)
{
	if constexpr (TypeTraits::IsNonblockingInputStream::T <Stream>::value)
	{
		return Blocking::InputStream::T (std::forward <Stream> (stream));
	}

	if constexpr (TypeTraits::IsInputStream::T <Stream>::value)
	{
		return std::forward <Stream> (stream);
	}

	if constexpr (TypeTraits::IsNonblockingOutputStream::T <Stream>::value)
	{
		return Blocking::OutputStream::T (std::forward <Stream> (stream));
	}

	if constexpr (TypeTraits::IsOutputStream::T <Stream>::value)
	{
		return std::forward <Stream> (stream);
	}
}
