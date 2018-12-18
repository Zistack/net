template <class Element>
std::optional<Delay::T<Element>>
T<Element>::tryPop ()
{
	return this->queue.tryPop ();
}
