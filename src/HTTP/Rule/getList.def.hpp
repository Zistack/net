template <typename InputStream, typename ParseElement>
std::list <std::invoke_result_t <ParseElement, InputStream>>
getList (InputStream && input_stream, ParseElement && parseElement)
{
	using Element = std::invoke_result_t <ParseElement, InputStream>;

	std::list <Element> elements;

	try
	{
		while (true)
		{
			if (IO::Util::test (std::forward <InputStream> (input_stream), ','))
			{
				input_stream . get ();
				Util::skipWhitespace
				(
					std::forward <InputStream> (input_stream)
				);
				continue;
			}

			if (input_stream . eof ()) return elements;

			elements . push_back
			(
				parseElement (std::forward <InputStream> (input_stream))
			);

			Util::skipWhitespace (std::forward <InputStream> (input_stream));

			if (IO::Util::test (std::forward <InputStream> (input_stream), ','))
			{
				input_stream . get ();
				Util::skipWhitespace
				(
					std::forward <InputStream> (input_stream)
				);
				continue;
			}
			else return elements;
		}
	}
	catch (Failure::EndOfResource::T)
	{
		return elements;
	}
}
