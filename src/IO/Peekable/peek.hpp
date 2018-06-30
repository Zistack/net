CharType
peek ()
{
	if (! this -> peekable)
	{
		this -> peek_char = this -> input_stream -> get ();
		this -> peekable = true;
	}
	return this -> peek_char;
}
