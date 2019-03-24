template <typename ... Cancellables>
T <Cancellables ...>::T () : cancelled (false), cancellable (nullptr)
{
}
