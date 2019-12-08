template <typename Interface>
void
T <Interface>::finalizeMessage ()
{
	this -> interface () . dispatch (std::move (* this -> m_message));

	this -> m_message = std::nullopt;
}
