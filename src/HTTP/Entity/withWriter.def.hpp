template <typename Visitor>
auto
T::withWriter (Visitor && visitor)
{
	return std::visit
	(
		[&] (auto && data)
		{
			return visitor (IO::Util::ensureBlocking (data . writer ()));
		},
		this -> data
	);
}
