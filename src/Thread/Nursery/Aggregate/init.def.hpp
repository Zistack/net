template <bool use_external_store, typename ... Cancellables>
template <typename ... ArgumentPacks>
void
T <use_external_store, Cancellables ...>::init
(
	ArgumentPacks && ... argument_packs
)
{
	TypeTraits::map
	(
		[&] (auto & thread, auto && arguments)
		{
			this -> wrapFunction
			(
				thread,
				std::forward <decltype (arguments)> (arguments)
			);
		},
		this -> m_threads,
		std::forward_as_tuple
		(
			std::forward <ArgumentPacks> (argument_packs) ...
		)
	);
}
