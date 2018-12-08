void
T::addStage (std::unique_ptr<TransferEncoding::T> && transfer_encoding)
{
	this->stages.emplace_back (std::move (transfer_encoding));
}
