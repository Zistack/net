template <typename Wrapper>
using T = GetConfig::Section::T
<
	Wrapper,
	GetConfig::Member::T
	<
		GetConfig::String::T,
		false,
		CERTIFICATE_FILENAME,
		CERTIFICATE_FILENAME_DESCRIPTION
	>,
	GetConfig::Member::T
	<
		GetConfig::String::T,
		false,
		PRIVATE_KEY_FILENAME,
		PRIVATE_KEY_FILENAME_DESCRIPTION
	>
>;
