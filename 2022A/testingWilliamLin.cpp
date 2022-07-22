
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

template<class T> bool umin(T& a, const T& b) {
	return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
	return a<b?a=b, 1:0;
} 

ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb)/2;
		f(mb)?rb=mb:lb=mb+1; 
	} 
	return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb+1)/2;
		f(mb)?lb=mb:rb=mb-1; 
	} 
	return lb;
}

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}

string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vt<bool> v) {
	string res;
	FOR(sz(v))
		res+=char('0'+v[i]);
	return res;
}

template<size_t S> string to_string(bitset<S> b) {
	string res;
	FOR(S)
		res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
    return res;
}

template<class A> void write(A x) {
	cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}

void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

template<class T> void offset(ll o, T& x) {
	x+=o;
}
template<class T> void offset(ll o, vt<T>& x) {
	EACH(a, x)
		offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
	EACH(a, x)
		offset(o, a);
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(mt_rng);
}

template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
	v=vt<T>(n, x);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
	v=vt<T>(n);
	EACH(a, v)
		vti(a, x, m);
}

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

// Using digit dynamic programming

// stores gcds for each digit and each possible total
int pt[109][10];
// For the dynamic programming
ll dp[14][2][109][109];

ll solve2(ll x) {
	ll ans=0;
    // Iterates over all the possible total digit sums
	FOR(ts, 1, 109) {
        // Clears all of dp[0] 
		memset(dp[0], 0, sizeof(dp[0]));
        // Sets there to be one in the maximum depth at ts
		dp[0][0][0][ts]=1;
        // Copies x so that it isn't mutilated
		ll x2=x;
        // Iterates over all of the possible digit lengths
		FOR(i, 1, 14) {
			// Clears the dp array with index i
            memset(dp[i], 0, sizeof(dp[0]));
            // Gets the current digit
			int d=x2%10;
            // Iterates over the second dimension of dp
            // Unsure of the purpose of this variable, goes from 0 to 1
			// I think that this is a boolean for checking if the value is greater
            // than the cap or not and stores it in a different place if so
            // if j is 1 that is for the valid ones, if j = 0 that is for the invalid ones
            // however, they can become valid if a later digit is less than x2 later
            FOR(j, 2) {
                // Iterates over the digit sums
				FOR(s, 109) {
                    // Iterates over the product of the digits
					FOR(p, 109) {
                        // If the value of dp at the location it would copy from
                        // If that location is empty nothing will come of it
						if(!dp[i-1][j][s][p])
							continue;
                        // Iterates over new digits
						FOR(nd, 10) {
                            // If s + digit is greater than ts, no more digits need
                            // to be iterated and we can break
							if(s+nd>ts)
								break;
                            // This is where the magic happens!
                            // Adds the dp value in previous i value, j, s, p
                            // to the current i value, new digit < digit + j,
                            // sum + new digit, pt of p new digit
							dp[i][nd<d+j][s+nd][pt[p][nd]]+=dp[i-1][j][s][p];
                            // if new digit isn't zero (no leading zeros) and
                            // new digit < digit + j or leftover total > 9 
                            // if it is lower or if it can be fixed in the future it
                            // is also kept as valid
                            // (this validates that the number is less than target) and
                            // total + newdigit == total sum (attempting get totalsum)and
                            // the product divided by the new digit is 1 (divides cleanly)
                            if(nd&&(nd<d+j||x2>9)&&s+nd==ts&&pt[p][nd]==1)
                                // The value in dp previous value of i, j, s, p
                                // is added to the answer
								ans+=dp[i-1][j][s][p];
						}
					}
				}
			}
            // Removes the last digit from the number
			x2/=10;
		}
    }
	return ans;
}

void solve() {
	ll a, b;
	read(a, b);
	// Gets the number of interesting numbers under b+1 minus under a
	print(solve2(b+1)-solve2(a));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    // Iterates through all of the possible digit sums
	FOR(p, 1, 109)
        // Iterates through all the possible digits
		FOR(d, 10)
            // Stores p over thegreatest common divisor of the digit and the total in pt
			pt[p][d]=p/__gcd(p, d);

    /*
    FOR(i, 1, 109) {
        FOR(d, 10)
            cout << pt[i][d] << " ";
        cout << "\n";
    }
    */
	int t=1;
	read(t);
	FOR(t) {
		write("Case #", i+1, ": ");
		solve();
	}
}
