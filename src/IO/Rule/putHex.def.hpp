template <typename Number, typename OutputStream, typename>
void
putHex (Number num, OutputStream && output_stream)
{
	output_stream . print (Util::toHex (num));
}
