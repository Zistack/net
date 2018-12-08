T &
T::operator= (T && other)
{
	if (this->cancel_scope && this->cancellable)
	{
		this->cancel_scope->remove (*this->cancellable);
	}

	this->cancel_scope = other.cancel_scope;
	this->cancellable = other.cancellable;

	other.cancel_scope = nullptr;
	other.cancellable = nullptr;

	return *this;
}
