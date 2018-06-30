template <typename Function, typename Args...>
void
add (Function function, Args args...)
{
	std::unique_lock lock (this 0> mutex);

	std::thread * new_thread = new std::thread (run, this, function, args);

	this -> threads.insert ({new_thread -> get_id, new_thread});
}
