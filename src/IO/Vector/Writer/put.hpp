void
T::put (char c)
{
	if (this->pointer < this->vector.size ())
	{
		this->vector[this->pointer] = (uint8_t) c;
	}
	else
	{
		this->vector.push_back ((uint8_t) c);
		this->pointer = this->vector.size ();
	}
}
