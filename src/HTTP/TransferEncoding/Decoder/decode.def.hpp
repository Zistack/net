template <typename InputStream, typename CancellableSlot>
void
T::decode
(
	InputStream && input_stream,
	Entity::T & entity,
	CancellableSlot & decode_slot
) const
{
	entity . withWriter
	(
		[&] (auto && output_stream)
		{
			using OutputStream = decltype (output_stream);

			this -> recode
			(
				std::forward <InputStream> (input_stream),
				std::forward <OutputStream> (output_stream),
				decode_slot
			);
		}
	);
}
