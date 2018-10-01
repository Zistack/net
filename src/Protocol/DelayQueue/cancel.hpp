template <class Element>
void
T<Element>::cancel ()
{
	this->queue.cancel ();

	try
	{
		while (true)
		{
			Delay::T<Element> delay = this->queue.pop ();
			delay.cancel ();
		}
	}
	catch (Failure::CancelException::T)
	{
	}
}
