template <typename Output>
Crypto::RNG::T &
T <Output>::rng ()
{
	return static_cast <Output &> (* this) . m_rng;
}
