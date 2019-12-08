template <typename OutputStream, typename CancellableSlot>
void
T::encode
(
	const Entity::T & entity,
	OutputStream && output_stream,
	CancellableSlot & encode_slot
) const
{
	entity . withReader
	(
		[&] (auto && input_stream)
		{
			using InputStream = decltype (input_stream);

			this -> recode
			(
				std::forward <InputStream> (input_stream),
				std::forward <OutputStream> (output_stream),
				encode_slot
			);
		}
	);
}
