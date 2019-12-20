template <typename Wrapper>
using T = GetConfig::Section::T
<
	Wrapper,
	GetConfig::Member::T
	<
		TCP::Config::T,
		false,
		TCP_CONFIG,
		TCP_CONFIG_DESCRIPTION
	>,
	GetConfig::Member::T
	<
		GetConfig::URI::Path::T,
		true,
		CA_PATH,
		CA_PATH_DESCRIPTION
	>,
	GetConfig::Member::T <KeyPair::T, false, IDENTITY, IDENTITY_DESCRIPTION>,
	GetConfig::Member::T
	<
		GetConfig::Duration::T,
		false,
		HANDSHAKE_TIMEOUT,
		HANDSHAKE_TIMEOUT_DESCRIPTION,
		HANDSHAKE_TIMEOUT_DEFAULT
	>,
	GetConfig::Member::T
	<
		GetConfig::UInt::T,
		false,
		MAX_RECORD_SIZE,
		MAX_RECORD_SIZE_DESCRIPTION,
		MAX_RECORD_SIZE_DEFAULT
	>
>;
