template
<
	typename OutputStream,
	typename CancellablePack =
		TransferEncoding::Encoder::CancellableSlot::T <OutputStream>
>
struct T;
