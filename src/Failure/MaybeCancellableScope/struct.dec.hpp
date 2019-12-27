template
<
	typename CancelSlot,
	typename Cancellable,
	bool is_cancellable = IsCancellable::T <Cancellable>::value
>
struct T;
