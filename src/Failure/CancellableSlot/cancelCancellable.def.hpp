template <typename ... Cancellables>
void
T <Cancellables ...>::cancelCancellable ()
{
	std::visit
	(
		[] (auto && cancellable)
		{
			using Cancellable = decltype (cancellable);

			if constexpr
			(
				! std::is_same_v
				<
					std::remove_cv_t <std::remove_reference_t <Cancellable>>,
					std::nullptr_t
				>
			)
			{
				cancellable . cancel ();
			}
		},
		this -> m_cancellable
	);
}
