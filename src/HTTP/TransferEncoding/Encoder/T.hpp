T::T (const Config::T & config, size_t entity_size) : config (config)
{
	if (this->config.transfer_encoding)
	{
		Header::TransferEncoding::T transfer_encoding (
		    this->config.transfer_encoding);

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

		this->addLastStage (last_specification);
	}
	else
	{
		this->setBoundedIdentity (entity_size);
	}
}
