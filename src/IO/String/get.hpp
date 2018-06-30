CharType
get ()
{
	if (this -> pointer < this -> string.size ())
	{
		CharType c = * this -> string [this -> pointer];
		++ this -> pointer;
		return c;
	}
	else throw EOF::T ();
}
