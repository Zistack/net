T::T (const Config::Value::T & config, size_t entity_size)
{
	NullableString::T transfer_encoding_string = config.getTransferEncoding ();

	if (transfer_encoding_string)
	{
		Header::TransferEncoding::T transfer_encoding (
		    transfer_encoding_string.stdString ());

		// We're going to assume that the specification is both nonempty and
		// terminated with the 'chunked' encoding.  If it is not, then we're
		// boned.

		TransferEncoding::Specification::T last_specification =
		    transfer_encoding.specifications.back ();
		transfer_encoding.specifications.pop_back ();

		for (TransferEncoding::Specification::T & specification :
		    transfer_encoding.specifications)
		{
			this->addStage (specification);
		}

		this->addLastStage (last_specification, config.getChunkSize ());
	}
	else
	{
		this->setBoundedIdentity (entity_size);
	}
}
