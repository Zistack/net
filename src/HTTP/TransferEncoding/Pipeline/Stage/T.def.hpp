template <typename ... Recoders>
template <typename ... Arguments>
T <Recoders ...>::T (Arguments && ... arguments)
:	recoder (std::forward <Arguments> (arguments) ...)
{
}
