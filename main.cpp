#include "CStack.h"
#include "Factory.h"
//#include "Functions.h"

int main() {

    string s1 = "file1";
//    string s2 = "file2";
    vector <int> vect1(10);
    for (size_t i = 0 ; i < 10; ++i)
        vect1[i] = i;
//    vector <int> vect2(6);
//    for (size_t i = 0 ; i < 6; ++i)
//        vect2[i] = i;
    CData1 st1(10, s1, vect1);
//    CData0 st2(6, s2, vect2);
//    st1.output();
//    st2.output();
//    cout << st1 << endl;
//    cout << st1 + st2 << endl;

//    (st1.container).pop();
//    stack <int> st;
//    st.push(1);
//    st.pop();
//    st.pop();
//    cout << st.size();

    CData0 a(7);

    vector <Factory*> f = {new FactoryCData0, new FactoryCData1};
    vector <CStack*> arr;
    size_t n = 0, e = 0;
    ifstream in("input.txt");
    string str;

    try {
        while (getline(in,str)) {
            if (str.size() == 0) {
                ++e;
                continue;
            }
            CStack* tmp = CStack::create_by_Factory(str, f);
            arr.push_back(tmp);
            ++e;
            ++n;
        }
        cout << "--------------------" << endl;
        for (size_t i = 0; i < n; ++i)
            arr[i]->output();

        cout << "The output to output-files was made" << endl;
        // cyclic shift testing
//        cout << "--------------------" << endl;
//        cout << "Cyclic shift testing" << endl;
//        cout << "Before cyclic shift:" << endl;
//        for (size_t i = 0; i < n; ++i)
//            cout << *arr[i] << endl;

        // cyclic shift
        CData0 tmpCDataObj(*arr[0]);
        for (size_t i = 0; i < n - 1; ++i)
            *arr[i] = *arr[i + 1];
        *arr[n - 1] = tmpCDataObj;

//        cout << "After:" << endl;
//        for (size_t i = 0; i < n; ++i)
//            cout << *arr[i] << endl;
//        cout << "--------------------" << endl;

        for (size_t i = 0; i < n; ++i)
            arr[i]->output();
        cout << "The output to output-files was made" << endl;
        cout << "--------------------" << endl;
        // incrementing and decrementing testing
        cout << "---------------------" << endl;
        cout << "Incrementing testing:" << endl;
        cout << "Object at the beginning: " << st1 << endl;
        cout << "Return prefix value: " << --st1 << endl;
        cout << "Return postfix value: " << st1-- << endl;
        cout << "After postfix:" << st1 << endl;
        cout << "Return prefix value: " << --st1 << endl;
        cout << "Return prefix value: " << --st1 << endl;
        cout << "---------------------" << endl;
        // operator + testing
        cout << "--------------------" << endl;
        cout << "Operator + testing" << endl;
        cout << (*arr[4]) << " + " <<  (*arr[1]) << " = ";
        cout << (*arr[4]) + (*arr[1]) << endl;
        cout << (*arr[0]) << " + " <<  (*arr[2]) << " = ";
        cout << (*arr[0]) + (*arr[2]) << endl;
        cout << (*arr[3]) << " + " <<  (*arr[4]) << " = ";
        cout << (*arr[3]) + (*arr[4]) << endl;
        cout << "--------------------" << endl;

        // adding objects in sum
        CData0 sum(0);
        for (size_t i = 0; i < n; ++i)
            sum = sum + *arr[i];

        cout << "sum = " << sum << endl;
        cout << "--------------------" << endl;

    }
    catch (int i) {
        if (i == -1) {
            cout << "Incorrect type(string " << e + 1 << ")\n";
        }
        if (i == -2) {
            cout << "Incorrect data(string " << e + 1 << ")\n";
        }
    }

    for (size_t i = 0; i < n; ++i)
        delete arr[i];
    for (size_t i = 0; i < 2; ++i)
        delete f[i];

    in.close();

    return 0;
}