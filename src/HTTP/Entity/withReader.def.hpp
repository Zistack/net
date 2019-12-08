template <typename Visitor>
auto
T::withReader (Visitor && visitor) const
{
	return std::visit
	(
		[&] (auto && data)
		{
			return visitor (IO::Util::ensureBlocking (data . reader ()));
		},
		this -> m_data
	);
}
