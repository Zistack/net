template <typename NonblockingOutputStream>
void
T<NonblockingOutputStream>::put (char c)
{
	this->buffer[this->next] = c;
	++this->next;

	if (this->next == BUFFER_SIZE)
	{
		this->flush ();
	}
}
