using T = Pipeline::Stage::T
<
	Chunked::Decode::T,
	BoundedIdentity::T,
	UnboundedIdentity::T
>;
