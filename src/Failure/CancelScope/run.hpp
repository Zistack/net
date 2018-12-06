template <class Function, class... Arguments>
void
T::run (Function && f, Arguments &&... arguments, Cancellable::T & cancellable)
{
	this->add (cancellable);

	f (std::forward<Arguments> (arguments)...);

	this->remove (cancellable);
}
