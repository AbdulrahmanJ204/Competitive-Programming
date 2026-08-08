// ============================================================================
//                           DATA STRUCTURES
// ============================================================================

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// Purpose: Ordered Set - maintains elements in sorted order with rank queries
// Time: O(log n) for insert, erase, find_by_order, order_of_key
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename R>
using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// For multiset behavior (allows duplicates)
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/* USAGE EXAMPLES:
ordered_set<int> s;
s.insert(1); s.insert(3); s.insert(2);
cout << *s.find_by_order(1) << endl; // 2 (1st indexed element, 0-indexed)
cout << s.order_of_key(2) << endl;   // 1 (number of elements < 2)
s.erase(s.find_by_order(0));         // Remove smallest element

ordered_map<int, string> mp;
mp.insert({1, "one"}); mp.insert({3, "three"});
cout << mp.find_by_order(0)->second << endl; // "one"


*/

// Purpose: Custom Hash for unordered containers to avoid collision attacks
// Time: O(1) expected
struct custom_hash {
    static uint64_t splitmix64(uint64_t z) {
        z += 0x9e3779b97f4a7c15;
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
        z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
        return z ^ (z >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename T>
using hash_set = unordered_set<T, custom_hash>;
template <typename T, typename U>
using hash_map = unordered_map<T, U, custom_hash>;

/* USAGE EXAMPLES:
hash_set<int> s;
s.insert(1); s.insert(2);

hash_map<int, string> mp;
mp[1] = "one"; mp[2] = "two";

unordered_set<int, custom_hash> safe_set;
unordered_map<int, int, custom_hash> safe_map;
ORDERED SET USAGE:
================
ordered_set<int> s;
s.insert(1); s.insert(3); s.insert(2);
cout << *s.find_by_order(1) << endl;   // 2 (1st indexed element, 0-based)
cout << s.order_of_key(2) << endl;     // 1 (number of elements < 2)
s.erase(s.find_by_order(0));           // Remove smallest element
// To remove specific element: s.erase(s.find(x));

ordered_multiset<int> ms;              // Allows duplicates
ms.insert(1); ms.insert(1); ms.insert(2);
cout << ms.order_of_key(2) << endl;    // 2 (elements < 2)

ordered_map<int, string> mp;
mp.insert({1, "one"}); mp.insert({3, "three"});
cout << mp.find_by_order(0)->second << endl; // "one"

UNORDERED MAP/SET WITH CUSTOM HASH:
==================================
// Safer than default hash (avoids collision attacks)
unordered_set<int, custom_hash> safe_set;
unordered_map<int, int, custom_hash> safe_map;

// Or use the typedef versions:
hash_set<int> hs;
hash_map<int, string> hm;

// Example usage:
safe_set.insert(42);
safe_map[1] = 100;
if (safe_set.count(42)) cout << "Found\n";

*/

