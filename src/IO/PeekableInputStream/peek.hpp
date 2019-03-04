template <typename InputStream>
char
T<InputStream>::peek ()
{
	if (!this->peekable)
	{
		this->peek_char = this->input_stream.get ();
		this->peekable = true;
	}
	return this->peek_char;
}
