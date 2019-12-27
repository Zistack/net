template <typename CancelSlot, typename Cancellable>
T <CancelSlot, Cancellable, true>::T
(
	CancelSlot & cancel_slot,
	Cancellable & cancellable
)
:	Scope::T <CancelSlot> (cancel_slot, cancellable)
{
}

template <typename CancelSlot, typename Cancellable>
T <CancelSlot, Cancellable, false>::T
(
	CancelSlot & cancel_slot,
	Cancellable & cancellable
)
{
}
