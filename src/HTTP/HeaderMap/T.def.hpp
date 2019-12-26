template <typename InputStream, typename>
T::T (InputStream && input_stream)
{
	while (! IO::Util::test (std::forward <InputStream> (input_stream), '\r'))
	{
		std::string field_name = Util::normalize
		(
			Rule::getToken (std::forward <InputStream> (input_stream))
		);

		IO::Util::expect (std::forward <InputStream> (input_stream), ':');

		Util::skipWhitespace (std::forward <InputStream> (input_stream));

		std::string field_value;

		while
		(
			! IO::Util::test (std::forward <InputStream> (input_stream), '\r')
		)
		{
			std::string value_part = Rule::getVChars
			(
				std::forward <InputStream> (input_stream)
			);

			if (! field_value . empty ()) field_value . push_back (' ');
			field_value . append (value_part);

			Util::skipWhitespace (std::forward <InputStream> (input_stream));
		}

		IO::Util::expect (std::forward <InputStream> (input_stream), "\r\n");

		this -> m_map . emplace (field_name, field_value);
	}
}

template <typename Iterable, typename>
T::T (const Iterable & iterable)
:	m_map (iterable . begin (), iterable . end ())
{
}

T::T
(
	const std::initializer_list <std::pair <std::string, std::string>> &
		header_fields
)
:	m_map (header_fields . begin (), header_fields . end ())
{
}
