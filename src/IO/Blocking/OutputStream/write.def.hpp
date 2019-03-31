template <typename NonblockingOutputStream>
void
T <NonblockingOutputStream>::write (const char * buffer, size_t count)
{
	if (this -> next + count >= BUFFER_SIZE)
	{
		this -> flush ();

		this -> send (buffer, count);
	}
	else
	{
		memcpy (this -> buffer + this -> next, buffer, count);
		this -> next += count;
	}
}
