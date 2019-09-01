template <typename Bytes, typename Base64>
void
encodeWithoutPadding (Bytes && bytes, size_t count, Base64 && base64)
{
	static constexpr char lookup [] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	size_t from;
	size_t to;
	for (from = 0, to = 0; from + 2 < count; from += 3, to += 4)
	{
		base64 [to] = lookup [bytes [from] >> 2];
		base64 [to + 1] =
			lookup [((bytes [from] & 0x03) << 4) | (bytes [from + 1] >> 4)];
		base64 [to + 2] =
			lookup [((bytes [from + 1] & 0x0F) << 2) | (bytes [from + 2] >> 6)];
		base64 [to + 3] = lookup [bytes [from + 2] & 0x3F];
	}

	switch (count - from)
	{
	default:
	case 0:
		break;

	case 1:
		base64 [to] = lookup [bytes [from] >> 2];
		base64 [to + 1] = lookup [(bytes [from] & 0x03) << 4];
		break;

	case 2:
		base64 [to] = lookup [bytes [from] >> 2];
		base64 [to + 1] =
			lookup [((bytes [from] & 0x03) << 4) | (bytes [from + 1] >> 4)];
		base64 [to + 2] =
			lookup [(bytes [from + 1] & 0x0F) << 2];
		break;
	}
}
