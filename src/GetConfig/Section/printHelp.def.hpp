template <typename... MemberTypes>
template <typename OutputStream>
void
T <MemberTypes ...>::printHelp
(
	OutputStream && output_stream,
	size_t columns,
	size_t tabwidth,
	size_t indentation
)
{
	output_stream.print ("{\n");

	MemberPack::T <MemberTypes ...>::printHelp
	(
		std::forward <OutputStream> (output_stream),
		columns,
		tabwidth,
		indentation + 1
	);

	IO::Util::indent (std::forward <OutputStream> (output_stream), indentation);
	output_stream . print ("}\n");
}
