bool
T::status ()
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	return this->state;
}
