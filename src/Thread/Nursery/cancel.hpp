void
T::cancel ()
{
	std::unique_lock<decltype (this->m)> lock (this->m);
	for (auto pair : this->threads)
	{
		auto inner_pair = pair.second;
		auto cancel = inner_pair.second;
		if (cancel) cancel ();
	}
}
