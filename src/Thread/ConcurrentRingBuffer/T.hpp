template <class Element>
T<Element>::T (size_t size) :
    size (size),
    head (0),
    tail (0),
    elements (new Element[size])
{
}
