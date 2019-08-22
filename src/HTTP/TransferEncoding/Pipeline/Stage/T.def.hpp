template <typename ... Recoders>
template <typename ... Arguments>
T <Recoders ...>::T (Arguments && ... arguments)
:	m_recoder (std::forward <Arguments> (arguments) ...)
{
}
