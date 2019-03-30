void
T::cancel () noexcept
{
	if (this -> cancellable) this -> cancel_cancellable (this -> cancellable);
}
