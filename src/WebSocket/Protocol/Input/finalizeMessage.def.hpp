template <typename Dispatcher>
void
T <Dispatcher>::finalizeMessage ()
{
	this -> dispatcher . dispatch (std::move (* this -> message));

	this -> message = std::nullopt;
}
