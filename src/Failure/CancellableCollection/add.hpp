template <typename Cancellable>
void
T<Cancellable>::add (Cancellable & cancellable)
{
	this->cancellables[this->next] = &cancellable;
	++this->next;
}
