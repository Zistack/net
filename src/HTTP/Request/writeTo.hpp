void
T::writeTo (IO::Interface::OutputStream::T & output_stream,
    IO::CancelSignal::T & output_cancel_signal,
    Failure::CancelScope::T & cancel_scope,
    const TransferEncoding::Encoder::Config::Value::T &
        transfer_encoding_config) const
{
	{
		Failure::CancelScope::Bind::T output_cancel_binding (
		    cancel_scope, output_cancel_signal);

		output_stream.print (this->requestLineToString ());

		this->headers.writeTo (output_stream);

		if (this->entity)
		{
			Util::specToHeaders (*this->entity, transfer_encoding_config)
			    .writeTo (output_stream);
		}

		output_stream.print ("\r\n");
	}

	if (this->entity)
	{
		this->entity->reset ();

		TransferEncoding::Encoder::T encoder (
		    transfer_encoding_config, (size_t) this->entity->size ());

		encoder.encode (
		    *entity, output_stream, output_cancel_signal, cancel_scope);
	}
}
