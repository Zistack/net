template <typename NonblockingOutputStream>
void
T<NonblockingOutputStream>::flush ()
{
	if (!this->next) return;

	this->send (this->buffer, this->next);

	this->next = 0;
}
