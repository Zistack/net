template <typename Protocol, typename Dispatcher>
void
T <Protocol, Dispatcher>::finalizeMessage ()
{
	this -> m_dispatcher . dispatch (std::move (* this -> message));

	this -> m_message = std::nullopt;
}
