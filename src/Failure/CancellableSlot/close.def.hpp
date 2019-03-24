template <typename ... Cancellables>
void
T <Cancellables ...>::close ()
{
	std::unique_lock <decltype (this -> mutex)> lock (this -> mutex);

	this -> cancellable = nullptr;
}
