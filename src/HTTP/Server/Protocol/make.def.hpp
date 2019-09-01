template
<
	typename Responder,
	typename ... ResponderArguments,
	typename ... UpgradeSpecs
>
std::unique_ptr
<
	Connection::Protocol::T <Responder, typename UpgradeSpecs::Target ...>
>
T <Responder, std::tuple <ResponderArguments ...>, UpgradeSpecs ...>::make ()
{
	return std::apply
	(
		std::make_unique
		<
			Connection::Protocol::T
			<
				Responder,
				typename UpgradeSpecs::Targets ...
			>
		>,
		std::tuple_cat
		(
			std::make_tuple
			(
				this -> config . getInputTimeout (),
				this -> config . getOutputTimeout (),
				this -> config . getTransferEncodingConfig (),
				this -> config . getTempFileThreshhold (),
				this -> m_responder_arguments
			),
			this -> m_upgrade_arguments
		)
	);
}