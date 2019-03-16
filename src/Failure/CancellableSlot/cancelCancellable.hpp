template <typename... Cancellables>
void
T<Cancellables...>::cancelCancellable ()
{
	std::visit (
	    [](auto && cancellable) {
		    using Cancellable = decltype (cancellable);

		    if constexpr (!std::is_same_v<Cancellable, std::nullptr_t>)
		    {
			    cancellable.cancel ();
		    }
	    },
	    this->cancellable);
}
