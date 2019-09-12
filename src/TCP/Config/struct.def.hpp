struct T : Spec::T
{
	using InterfaceType = T;

	using Spec::T::T;

	std::optional <std::string>
	getHostname () const;

	void
	setHostname (const std::optional <std::string> & hostname);

	std::optional <std::string>
	getPort () const;

	void
	setPort (const std::optional <std::string> & port);
};
