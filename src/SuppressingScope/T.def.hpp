template <typename Scopable>
T <Scopable>::T () : scopable (nullptr), exception_store (nullptr)
{
}

template <typename Scopable>
template <typename ... Arguments>
T <Scopable>::T
(
	Scopable & scopable,
	Arguments && ... arguments,
	Failure::ExceptionStore::T & exception_store
)
:	scopable (& scopable),
	exception_store (& exception_store)
{
	scopable . open (std::forward <Arguments> (arguments) ...);
}

template <typename Scopable>
T <Scopable>::T (T && other)
:	scopable (other . scopable),
	exception_store (other . exception_store)
{
	other . scopable = nullptr;
	other . exception_store = nullptr;
}
