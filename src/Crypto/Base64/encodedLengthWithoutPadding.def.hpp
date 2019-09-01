constexpr size_t
encodedLengthWithoutPadding (size_t decoded_length)
{
	return ((decoded_length / 3) * 4) +
		((size_t) (bool) (decoded_length % 3)) +
		(decoded_length % 3);
}
