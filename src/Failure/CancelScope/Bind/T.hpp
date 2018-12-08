T::T () : cancel_scope (nullptr), cancellable (nullptr) {}

T::T (CancelScope::T & cancel_scope, Cancellable::T & cancellable) :
    cancel_scope (&cancel_scope),
    cancellable (&cancellable)
{
	if (this->cancel_scope->add (*this->cancellable))
		throw CancelException::T ();
}

T::T (T && other)
{
	if (this->cancel_scope && this->cancellable)
	{
		this->cancel_scope->remove (*cancellable);
	}

	this->cancel_scope = other.cancel_scope;
	this->cancellable = other.cancellable;

	other.cancel_scope = nullptr;
	other.cancellable = nullptr;
}
