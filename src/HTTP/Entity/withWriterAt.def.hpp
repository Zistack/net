template <typename Visitor>
auto
T::withWriterAt (Visitor && visitor, size_t position)
{
	return std::visit
	(
		[&] (auto && data)
		{
			auto output_stream =
				IO::Util::ensureBlocking (data . writerAt (position));

			if constexpr
			(
				std::is_same_v <decltype (visitor (output_stream)), void>
			)
			{
				visitor (output_stream);

				if constexpr
				(
					IO::IsBuffered::T <decltype (output_stream)>::value
				)
				{
					output_stream . flush ();
				}
			}
			else
			{
				auto ret = visitor (output_stream);

				if constexpr
				(
					IO::IsBuffered::T <decltype (output_stream)>::value
				)
				{
					output_stream . flush ();
				}

				return ret;
			}
		},
		this -> m_data
	);
}
