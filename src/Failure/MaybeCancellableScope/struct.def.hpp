template <typename CancelSlot, typename Cancellable>
struct T <CancelSlot, Cancellable, true> : Scope::T <CancelSlot>
{
	T (CancelSlot & cancel_slot, Cancellable & cancellable);

	~T () = default;
};

template <typename CancelSlot, typename Cancellable>
struct T <CancelSlot, Cancellable, false>
{
	T (CancelSlot & cancel_slot, Cancellable & cancellable);

	~T () = default;
};

template <typename CancelSlot, typename Cancellable>
T (CancelSlot & cancel_slot, Cancellable & cancellable) ->
	T <CancelSlot, Cancellable, IsCancellable::T <Cancellable>::value>;
