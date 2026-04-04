using namespace std;
typedef long long ll;

int main() {

	int n, m;
	cin >> n >> m;

	int one = n, two = n / 2, three = (n + 1) / 2, four = (n + 2) / 3;
	int ans = 1;

	if (m >= one) ans++;
	if (n >= 2 && m >= two) ans++;
	if (n >= 3 && m >= three) ans++;
	if (n >= 3 && m >= four) ans++;
	if (n >= 4 && m >= one + four) ans++;
	if (n >= 4 && m >= two + four) ans++;
	if (n >= 5 && m >= three + four) ans++;
	cout << ans;
	return 0;
}
