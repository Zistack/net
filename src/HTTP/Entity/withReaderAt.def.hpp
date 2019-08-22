template <typename Visitor>
auto
T::withReaderAt (Visitor && visitor, uint64_t position)
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
