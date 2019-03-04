template <typename InputStream>
char
T<InputStream>::get ()
{
	if (this->peekable)
	{
		this->peekable = false;
		return this->peek_char;
	}
	else
		return this->input_stream.get ();
}
