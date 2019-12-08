template <typename ... Recoders>
template <typename InputStream, typename OutputStream>
void
T <Recoders ...>::recode
(
	InputStream && input_stream,
	OutputStream && output_stream
) const
{
	std::visit
	(
		[&] (auto && recoder)
		{
			recoder . recode
			(
				std::forward <InputStream> (input_stream),
				std::forward <OutputStream> (output_stream)
			);
		},
		this -> m_recoder
	);
}
