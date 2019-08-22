template <typename Responder, typename ... UpgradeTargets>
Response::T
T <Responder, UpgradeTargets ...>::map (const Request::T & request)
{
	try
	{
		request . check ();

		const HeaderMap::T & headers = request . headers ();

		if (headers . contains ("Upgrade"))
		{
			Header::Upgrade::T upgrade (headers . at ("Upgrade"));

			std::unique_lock upgrade_lock (this -> m_upgrade_mutex);

			std::optional
			<
				typename UpgradeFactory::
					T <UpgradeTargets ...>::
					ResponseAndProtocol
			>
			response_and_protocol =
				this -> m_upgrade_factory . upgrade (upgrade, request);

			if (response_and_protocol)
			{
				return std::visit
				(
					[this] (auto && response_and_protocol)
					{
						auto && [response, protocol] = response_and_protocol;

						this -> m_upgrade_target = protocol;

						return response;
					},
					* response_and_protocol
				);
			}
		}

		return this -> m_responder . respond (request);
	}
	catch (const CodeError::T & e)
	{
		return e . toResponse (this -> m_temp_file_threshhold);
	}
}
