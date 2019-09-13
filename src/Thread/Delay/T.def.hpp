template <typename Element>
T <Element>::T () : m_promise (std::make_shared <std::promise <Element>> ())
{
}
