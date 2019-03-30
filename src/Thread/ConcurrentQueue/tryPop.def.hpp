template <typename Element>
std::optional <Element>
T <Element>::tryPop ()
{
	std::unique_lock lock (this -> m);

	if (! this -> elements . empty ())
	{
		Element element = std::move (elements . front ());
		this -> elements . pop_front ();
		return element;
	}
	else return {};
}
