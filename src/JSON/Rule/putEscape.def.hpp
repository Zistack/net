template <typename OutputStream>
void
putEscape (OutputStream && output_stream, char32_t c)
{
	if (IO::Class::basicMultilingualPlane (c))
	{
		output_stream . print (IO::Util::toHex ((char16_t) (c & 0xFFFF)));
	}

	if (IO::Class::supplementaryPlane (c))
	{
		output_stream . print ("\\u");
		output_stream . print
		(
			IO::Util::toHex ((char16_t) (((c >> 10) & 0x03FF) | 0xD800))
		);
		output_stream . print ("\\u");
		output_stream . print
		(
			IO::Util::toHex ((char16_t) (((c >> 0) & 0x03FF) | 0xDC00))
		);
	}
}
