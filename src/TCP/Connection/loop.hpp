void
loop (EPoll::T * epoll)
{
	try
	{
		while (true)
		{
			IO::EPoll::Watchable::T * ready_stream = epoll -> wait ();

			if (ready_stream == this -> socket) this -> protocol -> event ();
			else if (ready_stream == this -> signal) return;
		}
	}
	catch (IO::Error::T e) throw Error::T (e.what ());
	catch (std::exception e) throw Error::T (e.what ());
}
