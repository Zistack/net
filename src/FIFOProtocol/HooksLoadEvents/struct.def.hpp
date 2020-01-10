template <typename Interface>
struct T
{
	static constexpr bool value =
		HasWriteActive::T <Interface>::value &&
		HasWriteIdle::T <Interface>::value &&
		HasQueueActive::T <Interface>::value &&
		HasQueueIdle::T <Interface>::value &&
		HasReadActive::T <Interface>::value &&
		HasReadIdle::T <Interface>::value;
};
