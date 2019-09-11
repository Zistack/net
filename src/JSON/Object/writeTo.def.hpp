template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream, size_t indentation) const
{
	IO::Util::indent (std::forward <OutputStream> (output_stream), indentation);
	output_stream . put ('{');

	auto it = this -> m_members . begin ();
	for (; it != this -> m_members . end (); ++ it)
	{
		if (it != this -> m_members . begin ()) output_stream . put (',');
		output_stream . put ('\n');

		String::T json_string (it -> first);
		json_string . writeTo
		(
			std::forward <OutputStream> (output_stream),
			indentation + 1
		);

		output_stream . print (": ");

		it -> second -> writeTo (std::forward <OutputStream> (output_stream));
	}

	output_stream . put ('\n');

	IO::Util::indent (std::forward <OutputStream> (output_stream), indentation);
	output_stream . put ('}');
}
