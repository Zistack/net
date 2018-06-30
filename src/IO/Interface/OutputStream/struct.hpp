template <typename CharType>
struct T
{
	virtual void put (CharType c) = 0;

	void print (std::basic_string <CharType> message);
};
