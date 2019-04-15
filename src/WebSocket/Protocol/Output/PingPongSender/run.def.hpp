template <typename OutputStream>
void
T::run (OutputStream && output_stream)
{
	Scope::T output_scope (std::move (this -> output_scope));

	try
	{
		while (true)
		{
			auto [type, payload] = this -> output_queue . pop ();

			FrameHeader::T frame_header
			(
				true,
				false,
				false,
				false,
				type,
				payload . size (),
				{0}
			);

			this -> writeFrame
			(
				frame_header,
				payload,
				std::forward <OutputStream> (output_stream)
			);
		}
	}
	catch (Failure::EndOfResource::T)
	{
	}
}
