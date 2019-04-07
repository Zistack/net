template <typename Visitor>
auto
T::withReader (Visitor && visitor)
{
	return std::visit
	(
		[&] (auto && data)
		{
			return visitor (IO::Util::ensureBlocking (data . reader ()));
		},
		this -> data
	);
}
