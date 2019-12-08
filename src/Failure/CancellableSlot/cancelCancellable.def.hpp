template <typename ... Cancellables>
void
T <Cancellables ...>::cancelCancellable ()
{
	std::visit
	(
		[] (auto && cancellable_wrapper)
		{
			using CancellableWrapper = decltype (cancellable_wrapper);

			if constexpr
			(
				! std::is_same_v
				<
					std::remove_cv_t
					<
						std::remove_reference_t <CancellableWrapper>
					>,
					std::nullptr_t
				>
			)
			{
				cancellable_wrapper . get () . cancel ();
			}
		},
		this -> m_cancellable
	);
}
