template <class Element>
size_t
T<Element>::successor (size_t i) const
{
	if (i + 1 == this->size)
		return 0;
	else
		return i + 1;
}
