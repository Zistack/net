std::optional <std::string>
T::getHostname () const
{
	return {this -> get <Spec::HOSTNAME> ()};
}
