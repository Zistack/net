struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const std::optional <std::string> &
	hostname () const;

	std::optional <std::string> &
	hostname ();

	const std::optional <std::string> &
	port () const;

	std::optional <std::string> &
	port ();
};
