struct T : Spec::T
{
	using Value = T;

	using Spec::T::T;

	const GetConfig::Duration::T::Value &
	inputTimeout () const;

	GetConfig::Duration::T::Value &
	inputTimeout ();

	const GetConfig::Duration::T::Value &
	outputTimeout () const;

	GetConfig::Duration::T::Value &
	outputTimeout ();

	const TransferEncoding::Config::T &
	transferEncodingConfig () const;

	TransferEncoding::Config::T &
	transferEncodingConfig ();

	const GetConfig::UInt::T::Value &
	tempFileThreshhold () const;

	GetConfig::UInt::T::Value &
	tempFileThreshhold ();
};
