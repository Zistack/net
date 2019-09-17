template <typename ... Cancellables>
template <typename ... ArgumentPacks>
T <Cancellables ...>::T (ArgumentPacks && ... argument_packs)
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
