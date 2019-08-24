struct T
{
	template <typename SeedGenerator>
	T (SeedGenerator && getSeed);

	uint32_t
	generate (uint8_t * buffer, uint32_t count);

	~T () = default;

private:

	static struct kcapi_handle *
	newHandle ();

	std::unique_ptr <struct kcapi_handle, Functor::T <kcapi_rng_destroy>>
		m_handle;
};
