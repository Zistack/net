template <typename Base64, typename Bytes>
void
decode (Base64 && base64, size_t count, Bytes && bytes)
{
	if (base64 [count - 1] == '=')
	{
		-- count;
		if (base64 [count - 1] == '=') -- count;
	}

	auto lookup = [] (char c)
	{
		if (c >= 'A' && c <= 'Z') return c - 'A';
		if (c >= 'a' && c <= 'z') return c + (26 - 'a');
		if (c >= '0' && c <= '9') return c + (52 - '0');
		if (c == '+') return 62;
		if (c == '/') return 63;

		assert (0);
		return '\0';
	};

	size_t from;
	size_t to;
	for (from = 0, to = 0; from + 3 < count; from += 4, to += 3)
	{
		bytes [to] =
			(lookup (base64 [from]) << 2) | (lookup (base64 [from + 1]) >> 4);
		bytes [to + 1] =
			(lookup (base64 [from + 1]) << 4) |
			(lookup (base64 [from + 2]) >> 2);
		bytes [to + 2] =
			(lookup (base64 [from + 2]) << 6) | lookup (base64 [from + 3]);
	}

	switch (count - from)
	{
	default:
	case 0:
		break;

	case 2:
		bytes [to] =
			lookup (base64 [from]) << 2 | lookup (base64 [from + 1]) >> 4;
		break;

	case 3:
		bytes [to] =
			lookup (base64 [from]) << 2 | lookup (base64 [from + 1]) >> 4;
		bytes [to + 1] =
			(lookup (base64 [from + 1]) << 4) |
			(lookup (base64 [from + 2]) >> 2);
		break;
	}
}
