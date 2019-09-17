template <bool use_external_store, typename ... Cancellables>
template <typename ... ArgumentPacks>
T <use_external_store, Cancellables ...>::T
(
	ArgumentPacks && ... argument_packs
)
:	m_threads
	(
		std::make_from_tuple <Thread::T <Cancellable::T <ArgumentPacks>>>
		(
			std::apply
			(
				T::wrapFunction,
				std_tuple_cat (std::make_tuple (this), argument_packs)
			)
		) ...
	)
{
}

template <bool use_external_store, typename ... Cancellables>
template <typename ... ArgumentPacks>
T <use_external_store, Cancellables ...>::T
(
	Failure::ExceptionStore::T & exception_store,
	ArgumentPacks && ... argument_packs
)
:	ExceptionStore::T <use_external_store> (exception_store),
	m_threads
	(
		std::make_from_tuple <Thread::T <Cancellable::T <ArgumentPacks>>>
		(
			std::apply
			(
				T::wrapFunction,
				std::tuple_cat (std::make_tuple (this), argument_packs)
			)
		) ...
	)
{
}
