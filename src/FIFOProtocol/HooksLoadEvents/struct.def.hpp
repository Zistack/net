template <typename Interface>
struct T
{
	static constexpr bool value =
		HasReadActive::T <Interface>::value &&
		HasReadIdle::T <Interface>::value &&
		HasQueueActive::T <Interface>::value &&
		HasQueueIdle::T <Interface>::value &&
		HasWriteActive::T <Interface>::value &&
		HasWriteIdle::T <Interface>::value;
};
