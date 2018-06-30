Error::T
encode (char c, std::ostream * json_stream)
{
	json_stream->put ('\\');
	json_stream->put ('u');
	json_stream->put ('0');
	json_stream->put ('0');
	json_stream->put (nibbleToChar (((uint8_t) c >> 4)));
	json_stream->put (nibbleToChar ((uint8_t) c & 0x0F));

	return Error::NONE;
}
