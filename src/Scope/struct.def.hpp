template <typename Scopable>
struct T
{
	T ();

	template
	<
		typename ... Arguments,
		typename ProxyScopable = Scopable,
		typename = std::enable_if_t
		<
			std::is_convertible_v
			<
				decltype
				(
					std::declval <ProxyScopable> () .
						open (std::declval <Arguments> () ...)
				),
				void
			> &&
				std::is_convertible_v
				<
					decltype (std::declval <ProxyScopable> () . close ()),
					void
				>
		>
	>
	T (Scopable & scopable, Arguments && ... arguments);

	T (const T & other) = delete;

	T (T && other);

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other);

	~T ();

private:

	Scopable * m_scopable;
};

template <typename Scopable, typename ... Arguments>
T (Scopable & scopable, Arguments && ...) -> T <Scopable>;
