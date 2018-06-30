Element
pop ()
{
	std::unique_lock lock (mutex);

	while (true)
	{
		if (! elements . empty ())
		{
			Element element = elements . front ();
			elements . pop_front ();
			return element;
		}

		if (closed) return NULL;

		condition_variable . wait (lock);
	}
}
