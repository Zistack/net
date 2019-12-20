template <typename Wrapper>
using T = GetConfig::Section::T
<
	Wrapper,
	GetConfig::Member::T
	<
		GetConfig::URI::Host::T,
		true,
		HOSTNAME,
		HOSTNAME_DESCRIPTION
	>,
	GetConfig::Member::T <GetConfig::UInt::T, true, PORT, PORT_DESCRIPTION>
>;
