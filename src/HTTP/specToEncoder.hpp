void
specToEncoder (const Entity::T & entity,
    const NullableString::T & transfer_encoding_spec,
    TransferEncoding::Encoder::T & encoder)
{
	if (transfer_encoding_spec)
	{
		Header::TransferEncoding::T transfer_encoding (transfer_encoding_spec);

		// We're going to assume that the specification is both nonempty and
		// terminated with the 'chunked' encoding.  If it is not, then we're
		// boned.

		TransferEncoding::Specification::T last_specification =
		    transfer_encoding.specifications.back ();
		transfer_encoding.specifications.pop_back ();

		for (TransferEncoding::Specification::T & specification :
		    transfer_encoding.specifications)
		{
			encoder.addStage (specification);
		}

		encoder.addLastStage (last_specification);
	}
	else
	{
		encoder.setBoundedIdentity (entity.size ());
	}
}
