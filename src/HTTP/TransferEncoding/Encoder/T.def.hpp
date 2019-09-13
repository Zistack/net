T::T (const Config::T & config, size_t entity_size)
{
	const std::optional <std::string> & transfer_encoding_string =
		config . transferEncoding ();

	if (transfer_encoding_string)
	{
		Header::TransferEncoding::T transfer_encoding
		(
			* transfer_encoding_string
		);

		// We're going to assume that the specification is both nonempty and
		// terminated with the 'chunked' encoding.  If it is not, then we're
		// boned.

		Header::TransferEncoding::Specification::T last_specification =
			transfer_encoding . specifications . back ();
		transfer_encoding . specifications . pop_back ();

		for
		(
			Header::TransferEncoding::Specification::T & specification :
			transfer_encoding . specifications
		)
		{
			this -> addStage (specification);
		}

		this -> addLastStage (last_specification, config . chunkSize ());
	}
	else
	{
		this -> addBoundedIdentity (entity_size);
	}
}
