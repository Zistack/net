template <>
struct T <false>
{
	T () = default;

	~T () = default;

protected:

	Failure::ExceptionStore::T m_exception_store;
};

template <>
struct T <true>
{
	T (Failure::ExceptionStore::T & exception_store);

	~T () = default;

protected:

	Failure::ExceptionStore::T & m_exception_store;
};
