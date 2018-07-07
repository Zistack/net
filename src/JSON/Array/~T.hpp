T::~T ()
{
	for (Value::T * member : this->members)
	{
		delete member;
	}
}
