
//Algoretim 1;
#include <bits/stdc++.h>

using namespace std;

int BianrySearch(vector < int > & book_ids, int x) {

    int low = 0;
    int high = book_ids.size()-1;

    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (book_ids[mid] == x) {
            return 1;
        }
        else if (book_ids[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }


}
int UpperBoundSearch(vector < int > & book_ids, int x) {

    int low = 0;
    int high = book_ids.size();

    int mid;

    while (low < high) {
        mid = (low + high) / 2;
        
        if (book_ids[mid] <= x) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return low;
}

int LowerBoundSearch(vector < int > & book_ids, int x) {

    int low = 0;
    int high = book_ids.size();

    int mid;

    while (low < high) {
        mid = (low + high) / 2;

     if (book_ids[mid] >= x) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return low;

}
int main() {

    int n, x, flag = 0;
    vector < int > book_ids;

    cin >> n;
    for (int i = 0; i < n; i++) {

        cin >> x;
        book_ids.push_back(x);
    }

    cin >> x;

    if (BianrySearch(book_ids, x)) {
        cout << "Book found" << endl;

        cout << "Lower Bound index:" << LowerBoundSearch(book_ids, x) << endl;

        cout << "Upper Bound index:" << UpperBoundSearch(book_ids, x) << endl;

    } else {
        cout << "Book not found" << endl;
    }




}

//Algorithem 2:
#include <bits/stdc++.h>

using namespace std;

int BianrySearch(vector < int > & book_ids, int x) {

    int low = 0;
    int high = book_ids.size() - 1;

    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (book_ids[mid] == x) {
            return 1;
        }
        else if (book_ids[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;


}
int UpperBoundSearch(vector < int > & book_ids, int x) {

    int low = 0;
    int high = book_ids.size() - 1;

    int mid, target = book_ids.size();;

    while (low <= high) {
        mid = (low + high) / 2;

        if (book_ids[mid] > x) {
            target = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return target;
}

int LowerBoundSearch(vector < int > & book_ids, int x) {

    int low = 0;
    int high = book_ids.size() - 1;

    int mid, target = book_ids.size();;

    while (low <= high) {
        mid = (low + high) / 2;


        if (book_ids[mid] >= x) {
            target = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return target;

}
int main() {

    int n, x, flag = 0;
    vector < int > book_ids;

    cin >> n;
    for (int i = 0; i < n; i++) {

        cin >> x;
        book_ids.push_back(x);
    }

    cin >> x;

    if (BianrySearch(book_ids, x)) {
        cout << "Book found" << endl;

        cout << "Lower Bound index:" << LowerBoundSearch(book_ids, x) << endl;

        cout << "Upper Bound index:" << UpperBoundSearch(book_ids, x) << endl;

    } else {
        cout << "Book not found" << endl;
    }




}
