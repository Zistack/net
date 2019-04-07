template <typename OutputStream, typename CancellableSlot>
void
T::writeTo
(
	OutputStream && output_stream,
	CancellableSlot & output_slot,
	const TransferEncoding::Config::T & transfer_encoding_config
) const
{
	{
		Scope::T header_scope (output_slot, output_stream);

		this -> putRequestLine (std::forward <OutputStream> (output_stream));

		this -> headers . writeTo (std::forward <OutputStream> (output_stream));

		if (this -> entity)
		{
			Output::specToHeaders (* this -> entity, transfer_encoding_config) .
				writeTo (std::forward <OutputStream> (output_stream));
		}

		output_stream . print ("\r\n");
	}

	if (this -> entity)
	{
		TransferEncoding::Encoder::T encoder
		(
			transfer_encoding_config,
			(size_t) this -> entity -> size ()
		);

		encoder . encode
		(
			* entity,
			std::forward <OutputStream> (output_stream),
			output_slot
		);
	}
}
