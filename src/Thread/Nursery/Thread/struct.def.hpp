struct T
{
	template <typename Function, typename ... Arguments, typename Cancellable>
	T
	(
		Function && function,
		Arguments && ... arguments,
		Cancellable * cancellable
	) noexcept;

	T (const T & other) = delete;

	T (T && other) = default;

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other) = default;

	std::thread::id
	id () const noexcept;

	void
	cancel () noexcept;

	void
	reset () noexcept;

	~T ();

private:

	void * m_cancellable;
	void (* m_cancel_cancellable) (void *);

	std::thread m_thread;
};

static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
