#include<bits/stdc++.h>
using namespace std;

typedef struct{
    string Author;
    string Title;
    int year;

}Book;

void SelectionSort(vector<Book> &bookInfo){

    for(int i = 0; i < bookInfo.size() - 1; i++){
        int target = i;

        for(int j = i + 1; j < bookInfo.size(); j++){
            if(bookInfo[target].year < bookInfo[j].year){
                target = j;
            }

            else if(bookInfo[target].year == bookInfo[j].year){
                if(bookInfo[target].Author > bookInfo[j].Author){
                    target = j;
                }

                else if(bookInfo[target].Author == bookInfo[j].Author){
                    if(bookInfo[target].Title > bookInfo[j].Title){
                        target = j;
                    }
                }
            }
        }

        swap(bookInfo[i], bookInfo[target]);
    }
}

int main(){

    vector <Book> bookInfo;

    int n;
    cin >> n;
    cin.ignore();
    
    string temp;
    Book tempBook;

    for(int i = 0; i < n; i++){

        getline(cin, temp);
        int comma1 = temp.find(',');
        int comma2 = temp.find(',', comma1 + 1);

        tempBook.Title = temp.substr(0, comma1);
        tempBook.Author = temp.substr(comma1 + 2, comma2 - comma1 - 2);
        stringstream year(temp.substr(comma2 + 2));
        year >> tempBook.year;

        bookInfo.push_back(tempBook);
    }

    SelectionSort(bookInfo);

    for(int i = 0; i < n; i++){
        cout << bookInfo[i].Title << ", " << bookInfo[i].Author << ", " << bookInfo[i].year << endl;
    }

    return 0;
}