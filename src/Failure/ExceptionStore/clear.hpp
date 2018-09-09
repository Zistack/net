void
T::clear ()
{
	std::unique_lock<decltype (this->m)> (this->m);

	this->exception = nullptr;
}
