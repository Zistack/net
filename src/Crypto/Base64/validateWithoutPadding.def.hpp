template <typename Base64>
bool
validateWithoutPadding (Base64 && base64, size_t count_without_padding)
{
	if ((count_without_padding % 4) == 1) return false;

	size_t i;
	for (i = 0; i < count_without_padding; ++ i)
	{
		if (! Class::base64Data (base64 [i])) return false;
	}

	return true;
}
