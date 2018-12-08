void
headersToDecoder (const HeaderMap::T & headers,
    TransferEncoding::Decoder::T & decoder)
{
	if (headers.contains ("Transfer-Encoding"))
	{
		if (headers.contains ("Content-Length"))
		{
			// Bad shit.
		}

		Header::TransferEncoding::T transfer_encoding (
		    headers.at ("Transfer-Encoding"));

		if (transfer_encoding.specifications.empty ())
		{
			// WTF?  Bad shit.
		}

		TransferEncding::Specification::T last_specification =
		    transfer_encoding.specifications.back ();
		transfer_encoding.specifications.pop_back ();

		if (last_specification.identifier != "chunked")
		{
			if (request)
			{
				// Bad shit.
			}
			else
			{
				// Everything is fine, but we read until the connection is
				// closed.
			}
		}

		decoder.addFirstStage (last_specification);

		for (auto rit = transfer_encoding.specifications.rbegin ();
		     rit != transfer_encoding.rend ();
		     ++rit)
		{
			TransferEncoding::Speficiation::T & specification = *rit;
			decoder.addStage (specification);
		}
	}
	else
	{
		if (headers.contains ("Content-Length"))
		{
			Header::ContentLength::T content_length (
			    headers.at ("Content-Length"));

			decoder.setBoundedIdentity (content_length);
		}
		else
		{
			decoder.setUnboundedIdentity ();
		}
	}
}
