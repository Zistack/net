void
T::write (const char * buffer, size_t count)
{
	if (this -> next + count >= BUFFER_SIZE)
	{
		this -> flush ();

		this -> send (buffer, count);
	}
	else
	{
		memcpy (this -> buffer . get () + this -> next, buffer, count);
		this -> next += count;
	}
}
