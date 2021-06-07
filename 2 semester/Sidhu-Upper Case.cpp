string upercase(string n) {//Upper Case Function
	locale loc;
	char  r[20] = "\0";
	for (int i = 0; i < n.length(); i++)
		r[i] = toupper(n[i], loc);
	return r;
}