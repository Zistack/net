struct T
{
	T () = default;

	T (const Data::T & string);

	Size::T
	size () const;

	Reader::T
	reader () const;

	Reader::T
	readerAt (Size::T position) const;

	Writer::T
	writer ();

	Writer::T
	writerAt (Size::T position);

	~T () = default;

private:

	Data::T m_string;
};
