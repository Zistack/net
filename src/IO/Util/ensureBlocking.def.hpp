template <typename Stream>
auto
ensureBlocking (Stream && stream)
{
	if constexpr (IsNonblockingInputStream::T <Stream>::value)
	{
		return Blocking::InputStream::T (std::forward <Stream> (stream));
	}

	if constexpr (IsInputStream::T <Stream>::value)
	{
		return std::forward <Stream> (stream);
	}

	if constexpr (IsNonblockingOutputStream::T <Stream>::value)
	{
		return Blocking::OutputStream::T (std::forward <Stream> (stream));
	}

	if constexpr (IsOutputStream::T <Stream>::value)
	{
		return std::forward <Stream> (stream);
	}
}
