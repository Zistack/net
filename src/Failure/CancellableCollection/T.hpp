template <typename Cancellable>
T<Cancellable>::T (size_t size) :
    cancellables (new Cancellable *[size]),
    next (0)
{
}
