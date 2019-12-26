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

		this -> putHead (std::forward <OutputStream> (output_stream));

		if (this -> m_entity)
		{
			Output::specToHeaders
			(
				* this -> m_entity,
				transfer_encoding_config
			) .
				writeTo (std::forward <OutputStream> (output_stream));
		}

		output_stream . print ("\r\n");
	}

	if (this -> m_entity)
	{
		TransferEncoding::Encoder::T encoder
		(
			transfer_encoding_config,
			(size_t) this -> m_entity -> size ()
		);

		encoder . encode
		(
			* this -> m_entity,
			std::forward <OutputStream> (output_stream),
			output_slot
		);
	}
}

template <typename OutputStream>
void
T::writeTo
(OutputStream && output_stream) const
{
	this -> putHead (std::forward <OutputStream> (output_stream));

	if (this -> m_entity)
	{
		HeaderMap::T
		(
			{{"Content-Length", std::to_string (this -> m_entity -> size ())}}
		) .
			writeTo (std::forward <OutputStream> (output_stream));
	}

	output_stream . print ("\r\n");

	if (this -> m_entity)
	{
		this -> m_entity -> withReader
		(
			[&] (auto && input_stream)
			{
				while (! input_stream . eof ())
				{
					output_stream . put (input_stream . get ());
				}
			}
		);
	}
}
