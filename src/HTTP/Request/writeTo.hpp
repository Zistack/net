void
T::writeTo (const NullableString::T & transfer_encoding_spec,
    IO::Interface::OutputStream::T & output_stream,
    IO::CancelSignal::T & output_cancel_signal,
    Failure::CancelScope::T & cancel_scope) const
{
	{
		Failure::CancelScope::Bind::T output_cancel_binding (
		    cancel_scope, output_cancel_signal);

		output_stream.print (this->requestLineToString ());

		this->headers.writeTo (output_stream);

		if (this->entity)
		{
			Util::specToHeaders (*this->entity, transfer_encoding_spec)
			    .writeTo (output_stream);
		}

		output_stream.print ("\r\n");
	}

	if (this->entity)
	{
		this->entity->reset ();

		TransferEncoding::Encoder::T encoder;
		Util::specToEncoder (*this->entity, transfer_encoding_spec, encoder);

		encoder.encode (
		    *entity, output_stream, output_cancel_signal, cancel_scope);
	}
}
