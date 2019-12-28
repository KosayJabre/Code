#define point complex<double>
double dot(point a, point b) { return real(conj(a)*b); }
double cross(point a, point b) { return imag(conj(a)*b); }

struct line { point a, b; };
struct circle { point c; double r; };
struct triangle { point a, b, c; };
struct rectangle { point tl, br; };

#define sq(a) ((a)*(a))
double circumference(circle a) { return 2 * a.r * M_PI; }
double area(circle a) { return sq(a.r) * M_PI; }
double intersection(circle a, circle b) {
	double d = abs(a.c - b.c);
	if (d <= b.r - a.r) return area(a);
	if (d <= a.r - b.r) return area(b);
	if (d >= a.r + b.r) return 0;
	double alpha = acos((sq(a.r) + sq(d) - sq(b.r)) / (2 * a.r * d));
	double beta = acos((sq(b.r) + sq(d) - sq(a.r)) / (2 * b.r * d));
	return sq(a.r) * (alpha - 0.5 * sin(2 * alpha)) + sq(b.r) * (beta - 0.5 * sin(2 * beta));
}

double intersection(rectangle a, rectangle b) {
	double x1 = max(real(a.tl), real(b.tl)), y1 = max(imag(a.tl), imag(b.tl));
	double x2 = min(real(a.br), real(b.br)), y2 = min(imag(a.br), imag(b.br));
	return (x2 <= x1 || y2 <= y1) ? 0 : (x2-x1)*(y2-y1);
}
