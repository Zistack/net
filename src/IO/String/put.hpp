void
T::put (char c)
{
	if (this->pointer < this->string->size ())
		(*this->string)[this->pointer] = c;
	else
	{
		this->string->push_back (c);
		this->pointer = this->string->size ();
	}
}
