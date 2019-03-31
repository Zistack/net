template <typename InputStream>
void
expectEOF (InputStream && input_stream)
{
	if (! input_stream . eof ())
	{
		throw Failure::SyntaxError::T
		(
			Message::unexpectedCharacter (input_stream.peek ())
		);
	}
}
