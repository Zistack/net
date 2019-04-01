using T = GetConfig::Section::T
<
	GetConfig::Member::T
	<
		GetConfig::String::T,
		true,
		HOSTNAME,
		HOSTNAME_DESCRIPTION
	>,
	GetConfig::Member::T <GetConfig::String::T, true, PORT, PORT_DESCRIPTION>
>;
