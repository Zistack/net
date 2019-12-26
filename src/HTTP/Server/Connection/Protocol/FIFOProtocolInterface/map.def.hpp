template <typename Interface, typename ... UpgradeTargets>
Response::T
T <Interface, UpgradeTargets ...>::map (const Request::T & request)
{
	try
	{
		request . check ();

		const HeaderMap::T & headers = request . headers ();

		const std::string & request_host_string = headers . at ("Host");
		if (! request_host_string . empty ())
		{
			if (! this -> m_host_data)
			{
				throw CodeError::T
				(
					400,
					"Failed to validate Host header: No authority is defined "
						"for this server\n"
				);
			}

			Header::Host::T request_host = Header::Host::T (request_host_string);

			if (request_host . host != this -> m_host_data -> host . host)
			{
				throw CodeError::T
				(
					400,
					"Failed to validate Host header: Hostname does not match "
						"hostname of server\n"
				);
			}

			if
			(
				! request_host . port &&
				! this -> m_host_data -> using_default_port
			)
			{
				throw CodeError::T
				(
					400,
					"Failed to validate Host header: Port must be provided "
						"when using a non-default port\n"
				);
			}

			if
			(
				request_host . port &&
				(request_host . port != this -> m_host_data -> host . port)
			)
			{
				throw CodeError::T
				(
					400,
					"Failed to validate Host header: Port does match port of "
						"server\n"
				);
			}
		}
		else
		{
			if (this -> m_host_data)
			{
				throw CodeError::T
				(
					400,
					"Failed to validate Host header: An authority is defined "
						"for this server\n"
				);
			}
		}

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

						this -> m_upgrade_protocol = std::move (protocol);

						return std::move (response);
					},
					* response_and_protocol
				);
			}
		}

		return this -> interface () . respond (request);
	}
	catch (const CodeError::T & e)
	{
		return e . toResponse (this -> m_temp_file_threshhold);
	}
}
