struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const std::optional <URI::Authority::Host::T> &
	hostname () const;

	std::optional <URI::Authority::Host::T> &
	hostname ();

	const GetConfig::UInt::T::Value &
	port () const;

	GetConfig::UInt::T::Value &
	port ();
};
