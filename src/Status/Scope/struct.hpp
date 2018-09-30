struct T
{
	T (Bit::T & bit);
	T (const T & other) = delete;

	~T ();

	Bit::T & bit;
};
