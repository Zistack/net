template <class Element>
T<Element>::T () : promise (std::make_shared<std::promise<Element>> ())
{
}
