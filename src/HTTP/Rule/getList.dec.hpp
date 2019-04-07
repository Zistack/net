template <typename InputStream, typename ParseElement>
std::list <std::invoke_result_t <ParseElement, InputStream>>
getList (InputStream && input_stream, ParseElement && parseElement);
