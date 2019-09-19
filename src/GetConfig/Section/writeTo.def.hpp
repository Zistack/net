template <typename V, typename ... Members>
template <typename OutputStream>
void
T <V, Members ...>::writeTo
(
	OutputStream && output_stream,
	size_t indentation
) const
{
	output_stream.print ("{\n");

	this -> MemberPack::T <Members ...>::writeTo
	(
		std::forward <OutputStream> (output_stream),
		indentation + 1
	);

	IO::Util::indent (std::forward <OutputStream> (output_stream), indentation);
	output_stream . print ("}\n");
}

template <typename V, typename ... Members>
template <typename OutputStream>
void
T <V, Members ...>::writeTo
(
	const Value & value,
	OutputStream && output_stream,
	size_t indentation
)
{
	value . writeTo (std::forward <OutputStream> (output_stream), indentation);
}
