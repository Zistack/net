template <bool is_request>
std::optional <std::pair <TransferEncoding::Decoder::T, Entity::T>>
headersToEntity (const HeaderMap::T & headers, size_t temp_file_threshhold);