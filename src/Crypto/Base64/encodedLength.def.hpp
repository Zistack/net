constexpr size_t
encodedLength (size_t decoded_length)
{
	return ((decoded_length + 2) / 3) * 4;
}
