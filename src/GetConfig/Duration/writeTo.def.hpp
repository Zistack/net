template <typename OutputStream>
void
T::writeTo
(
	const Value & value,
	OutputStream && output_stream,
	size_t indentation
)
{
	uint64_t count = (uint64_t) value . count ();

	if (count % 1000)
	{
		output_stream . print (std::to_string (count));
		output_stream . print ("ns");
	}
	else if (count % 1000000)
	{
		output_stream . print (std::to_string (count / 1000));
		output_stream . print ("us");
	}
	else if (count % 1000000000)
	{
		output_stream . print (std::to_string (count / 1000000));
		output_stream . print ("ms");
	}
	else if (count % 1000000000000)
	{
		output_stream . print (std::to_string (count / 1000000000));
		output_stream . put ('s');
	}
	else if (count % 60000000000000)
	{
		output_stream . print (std::to_string (count / 1000000000000));
		output_stream . print ("min");
	}
	else
	{
		output_stream . print (std::to_string (count / 60000000000000));
		output_stream . put ('h');
	}
}
