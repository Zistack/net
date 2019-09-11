Reader::T
T::readerAt (Size::T position) const
{
	return {this -> m_string, position};
}
