struct T : Spec::T
{
	using Value = T;

	using Spec::T::T;

	const std::optional <std::string> &
	transferEncoding () const;

	std::optional <std::string> &
	transferEncoding ();

	const GetConfig::UInt::T::Value &
	chunkSize () const;

	GetConfig::UInt::T::Value &
	chunkSize ();
};
