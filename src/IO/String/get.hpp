char
T::get ()
{
	if (this->pointer < this->string.size ())
	{
		char c = this->string[this->pointer];
		++this->pointer;
		return c;
	}
	else
		throw EOF::T ();
}
