template <typename Base64>
bool
validate (Base64 && base64, size_t count)
{
	if (count % 4) return false;

	size_t i;
	for (i = 0; (i < count) && Class::base64Data (base64 [i]); ++ i);

	if ((count - i) > 2) return false;

	for (; (i < count) && (base64 [i] == '='); ++ i);

	return i == count;
}

template <typename Base64>
bool
validate (Base64 && base64, size_t count, size_t count_without_padding)
{
	if (count % 4) return false;
	if (count - count_without_padding > 2) return false;

	size_t i;
	for (i = 0; i < count_without_padding; ++ i)
	{
		if (! Class::base64Data (base64 [i])) return false;
	}

	for (; i < count; ++ i) if (base64 [i] != '=') return false;

	return true;
}

