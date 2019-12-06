template <typename Protocol, typename ... Arguments>
std::unique_ptr <Protocol>
T <Protocol, Arguments ...>::make ()
{
	return std::apply
	(
		[] (Arguments ... arguments)
		{
			return std::make_unique <Protocol>
			(
				std::forward <Arguments> (arguments) ...
			);
		},
		this -> m_arguments
	);
}
