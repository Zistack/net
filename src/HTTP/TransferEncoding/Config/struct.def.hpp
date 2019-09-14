struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const std::optional <std::string> &
	transferEncoding () const;

	std::optional <std::string> &
	transferEncoding ();

	const GetConfig::UInt::T::Value &
	chunkSize () const;

	GetConfig::UInt::T::Value &
	chunkSize ();
};
