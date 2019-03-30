template <typename Element>
void
T <Element>::push (const Element & element)
{
	std::unique_lock lock (this -> m);

	if (this -> closed) throw Failure::EndOfResource::T ();

	this -> elements . push_back (element);

	this -> c . notify_one ();
}

template <typename Element>
void
T <Element>::push (Element && element)
{
	std::unique_lock lock (this -> m);

	if (this -> closed) throw Failure::EndOfResource::T ();

	this -> elements.push_back (std::move (element));

	this -> c . notify_one ();
}
