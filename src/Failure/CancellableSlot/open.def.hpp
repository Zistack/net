template <typename ... Cancellables>
template <typename Cancellable>
void
T <Cancellables...>::open (Cancellable & cancellable)
{
	std::unique_lock <decltype (this -> mutex)> lock (this -> mutex);

	this -> cancellable = cancellable;

	if (this -> cancelled) this -> callCancellable ();
}
