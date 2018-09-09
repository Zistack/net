T::T (Failure::ExceptionStore::T & exception_store) :
    exception_store (exception_store)
{
}

T::T (Failure::ExceptionStore::T & exception_store,
    std::function<void(void)> callback) :
    exception_store (exception_store),
    callback (callback)
{
}
