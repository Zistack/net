template <class Element>
T<Element>::T () : promise (new std::promise<Element> ())
{
}
