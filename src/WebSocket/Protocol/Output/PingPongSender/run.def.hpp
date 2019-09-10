template <typename Output>
template <typename OutputStream>
void
T <Output>::run (OutputStream && output_stream)
{
	Scope::T output_scope (std::move (this -> m_output_scope));

	try
	{
		while (true)
		{
			auto [type, payload] = this -> m_output_queue . pop ();

			Masking::Key::T masking_key;
			{
				std::unique_lock rng_lock (this -> rngMutex ());
				this ->
					rng () .
					generate (masking_key . data (), masking_key . size ());
			}
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
