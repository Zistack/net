char
T::get ()
{
	if (this->begin == this->end)
	{
		this->refill ();
	}

	char c = this->buffer[this->begin];
	++this->begin;

	return c;
}
