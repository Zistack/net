T::~T ()
{
	this->m.lock ();

	this->stop = true;
	this->c.notify_one ();

	this->m.unlock ();

	this->thread.join ();
}
