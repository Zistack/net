template <typename ... Cancellables>
T <Cancellables ...>::T () : m_cancelled (false), m_cancellable (nullptr)
{
}
