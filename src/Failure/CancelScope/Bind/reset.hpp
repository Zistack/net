void
T::reset ()
{
	if (this->cancel_scope && this->cancellable)
	{
		this->cancel_scope->remove (*this->cancellable);
		this->cancel_scope = nullptr;
		this->cancellable = nullptr;
	}
}
