std::optional <std::string>
T::getTransferEncoding () const
{
	return {this -> get <Spec::TRANSFER_ENCODING> ()};
}
