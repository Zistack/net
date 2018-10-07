struct T
{
	T (Signal::T & signal,
	    Failure::ExceptionStore::T * exception_store = nullptr);
	T (const T & other) = delete;

	~T () noexcept (false);

	Signal::T & signal;
	Failure::ExceptionStore::T * exception_store;
};
