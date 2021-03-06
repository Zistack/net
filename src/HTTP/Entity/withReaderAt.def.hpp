template <typename Visitor>
auto
T::withReaderAt (Visitor && visitor, size_t position) const
{
	return std::visit
	(
		[&] (auto && data)
		{
			return visitor
			(
				IO::Util::ensureBlocking (data . readerAt (position))
			);
		},
		this -> m_data
	);
}
