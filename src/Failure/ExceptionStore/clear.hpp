void
T::clear ()
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	this->exception = nullptr;
}
