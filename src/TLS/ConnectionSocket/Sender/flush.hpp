void
T::flush ()
{
	if (!this->next) return;

	this->send (this->buffer.get (), this->next);

	this->next = 0;
}
