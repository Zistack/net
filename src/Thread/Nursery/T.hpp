T::T () noexcept :
    internal_store (std::make_unique<Failure::ExceptionStore::T> ()),
    exception_store (*internal_store)
{
}

T::T (Failure::ExceptionStore::T & exception_store) noexcept :
    exception_store (exception_store)
{
}
