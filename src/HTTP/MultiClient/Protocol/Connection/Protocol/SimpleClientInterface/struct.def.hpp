struct T : HTTP::Client::Protocol::T <T>
{
	void
	writeActive ();

	void
	writeIdle ();

	void
	queueActive ();

	void
	queueIdle ();

	void
	readActive ();

	void
	readIdle ();

protected:

	using HTTP::Client::Protocol::T <T>::T;

	double
	updateLoad ();

	~T () = default;

private:

	Thread::LoadMoniter::T m_write_load_moniter;
	Thread::LoadMoniter::T m_queue_load_moniter;
	Thread::LoadMoniter::T m_read_load_moniter;
};
