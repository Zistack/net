void
T::finalizeMessage (const FrameHeader::T & frame_header)
{
	this->message->finish ();

	this->dispatcher.dispatch (this->protocol, *this->message);

	this->message = nullptr;
}
