T::T (const Config::T & config, size_t entity_size)
{
	NullableString::T transfer_encoding_string =
		config . getTransferEncoding ();

	if (transfer_encoding_string)
	{
		Header::TransferEncoding::T transfer_encoding
		(
			transfer_encoding_string . stdString ()
		);

		// We're going to assume that the specification is both nonempty and
		// terminated with the 'chunked' encoding.  If it is not, then we're
		// boned.

		Header::TransferEncoding::Specification::T last_specification =
			transfer_encoding . m_specifications . back ();
		transfer_encoding . m_specifications . pop_back ();

		for
		(
			Header::TransferEncoding::Specification::T & specification :
			transfer_encoding . m_specifications
		)
		{
			this -> addStage (specification);
		}

		this -> addLastStage (last_specification, config . getChunkSize ());
	}
	else
	{
		this -> addBoundedIdentity (entity_size);
	}
}
