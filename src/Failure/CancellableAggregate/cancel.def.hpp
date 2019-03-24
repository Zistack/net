template <typename ... Cancellables>
void
T <Cancellables ...>::cancel ()
{
	this -> cancel (std::index_sequence_for <Cancellables ...> ());
}

template <typename ... Cancellables>
template <std::size_t ... N>
void
T <Cancellables ...>::cancel (std::index_sequence <N ...> indices)
{
	(std::get <N> (this -> cancellables) . cancel (), ...);
}
