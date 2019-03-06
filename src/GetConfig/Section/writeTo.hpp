template <typename... MemberTypes>
template <typename OutputStream>
void
T<MemberTypes...>::writeTo (OutputStream && output_stream,
    size_t indentation) const
{
	output_stream.print ("{\n");

	this->MemberPack::T<MemberTypes...>::writeTo (
	    std::forward<OutputStream> (output_stream), indentation + 1);

	IO::Util::indent (std::forward<OutputStream> (output_stream), indentation);
	output_stream.print ("}\n");
}
