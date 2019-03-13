template <typename... Cancellables>
T<Cancellables...>::T (Cancellables... cancellables) :
    cancellables (std::forward<Cancellables> (cancellables)...)
{
}
