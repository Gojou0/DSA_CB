#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    int expected = 1;
    stack<int> st;

    for (int i = 0; i < 2 * n; ++i) {
        string op;
        cin >> op;

        if (op == "add") {
            int x;
            cin >> x;
            st.push(x);
        } else { // "remove"
            if (!st.empty()) {
                if (st.top() == expected) {
                    st.pop();
                } else {
                    // Reset is only needed when top != expected
                    ans++;
                    while (!st.empty()) st.pop();
                }
            }
            expected++;
        }
    }

    cout << ans << endl;
    return 0;
}
