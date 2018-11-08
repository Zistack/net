std::thread::id
T::id () const
{
	if (this->thread.joinable ())
	{
		return this->thread.get_id ();
	}
	else
	{
		return std::this_thread::get_id ();
	}
}
