#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define putchar_unlocked(x) _putchar_nolock(x)
#endif

void read(unsigned int& n) {
	char c; n = 0;
	while ((c=getchar_unlocked())!=' '&&c!='\n')
		n = n * 10 + c - '0';
}

void read(int& n) {
	char c; n = 0; int s = 1;
	if ((c=getchar_unlocked())=='-') s = -1;
	else n = c - '0';
	while ((c=getchar_unlocked())!=' '&&c!='\n')
		n = n * 10 + c - '0';
	n *= s;
}

void read(ld& n) {
	char c; n = 0;
	ld m = 0, o = 1; bool d = false; int s = 1;
	if ((c=getchar_unlocked())=='-') s = -1;
	else if (c == '.') d = true;
	else n = c - '0';
	while ((c=getchar_unlocked())!=' '&&c!='\n') {
		if (c == '.') d = true;
		else if (d) { m=m*10+c-'0'; o*=0.1; }
		else n = n * 10 + c - '0';
	}
	n = s * (n + m * o);
}
void read(double& n) {
	ld m; read(m); n = m;
}
void read(float& n) {
	ld m; read(m); n = m;
}

void read(string& s) {
	char c; s = "";
	while((c=getchar_unlocked())!=' '&&c!='\n')
		s += c;
}

bool readline(string& s) {
	char c; s = "";
	while(c=getchar_unlocked()) {
		if (c == '\n') return true;
		if (c == EOF) return false;
		s += c;
	}
	return false;
}

void print(unsigned int n) {
	if (n / 10) print(n / 10);
	putchar_unlocked(n % 10 + '0');
}

void print(int n) {
	if (n < 0) { putchar_unlocked('-'); n*=-1; }
	print((unsigned int)n);
}
