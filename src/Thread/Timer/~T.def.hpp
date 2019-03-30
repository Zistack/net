T::~T ()
{
	{
		std::unique_lock lock (this -> m);

		this -> stop = true;
		this -> c . notify_one ();
	}

	this->thread.join ();
}
