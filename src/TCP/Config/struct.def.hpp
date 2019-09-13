struct T : Spec::T
{
	using Value = T;

	using Spec::T::T;

	const std::optional <std::string> &
	hostname () const;

	std::optional <std::string> &
	hostname ();

	const std::optional <std::string> &
	port () const;

	std::optional <std::string> &
	port ();
};
