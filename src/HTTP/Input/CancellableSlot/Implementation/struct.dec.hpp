template
<
	typename InputStream,
	typename CancellablePack =
		TransferEncoding::Decoder::CancellableSlot::T <InputStream>
>
struct T;
