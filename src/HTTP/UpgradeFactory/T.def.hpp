template <typename ... UpgradeTargets>
template <typename ... ResponseArguments, typename ... ProtocolArguments>
T <UpgradeTargets ...>::T (const std::pair <ResponseArguments, ProtocolArguments> & ... upgrade_arguments)
{
	(
		this -> m_upgrade_methods . emplace
		(
			UpgradeTargets::NAME . toString (),
			[
				response_arguments = upgrade_arguments . first,
				protocol_arguments = upgrade_arguments . second
			]
			(
				const Request::T & request
			)
			{
				using ResponseFactory =
					typename UpgradeTargets::ResponseFactory;

				ResponseFactory response_factory =
					std::make_from_tuple <ResponseFactory>
					(
						std::tuple_cat
						(
							std::forward_as_tuple (request),
							response_arguments
						)
					);

				std::unique_ptr <UpgradeTargets> protocol = std::apply
				(
					[]
					(
						const Request::T & request,
						const ResponseFactory & response_factory,
						ProtocolArguments & ... protocol_arguments
					)
					{
						return std::make_unique <UpgradeTargets>
						(
							request,
							response_factory,
							std::forward <ProtocolArguments>
							(
								protocol_arguments
							) ...
						);
					},
					std::tuple_cat
					(
						std::forward_as_tuple (request, response_factory),
						protocol_arguments
					)
				);

				return std::make_pair (response_factory . response, protocol);
			}
		), ...
	);
}
