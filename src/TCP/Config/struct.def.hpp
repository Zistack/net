struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const std::optional <URI::Authority::Host::T> &
	hostname () const;

	std::optional <URI::Authority::Host::T> &
	hostname ();

	const std::optional <uint64_t> &
	port () const;

	std::optional <uint64_t> &
	port ();
};
