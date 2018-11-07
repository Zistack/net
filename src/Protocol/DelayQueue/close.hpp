template <class Element>
void
T<Element>::close ()
{
	this->queue.close ();

	try
	{
		while (true) this->queue.pop ();
	}
	catch (Failure::CancelException::T)
	{
	}
}
