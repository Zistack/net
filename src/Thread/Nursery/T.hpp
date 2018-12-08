T::T () noexcept :
    cancelled (false),
    internal_store (std::make_unique<Failure::ExceptionStore::T> ()),
    exception_store (*internal_store)
{
}

T::T (Failure::ExceptionStore::T & exception_store) noexcept :
    cancelled (false),
    exception_store (exception_store)
{
}
