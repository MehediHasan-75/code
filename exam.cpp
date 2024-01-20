#include<bits/stdc++.h>
using namespace std;

pair< vector<vector<double>>, vector<double>> Input() {
    int number_of_unknown;
    cout << "Enter no. of unknowns in the system of linear equation: ";
    cin >> number_of_unknown;

    vector<vector<double>> co_efficient_matrix;
    vector<double> c(number_of_unknown, -1.0);

    for (int i = 0; i < number_of_unknown; ++i) {
        cout << "Input the coefficients of equation- " << i + 1 << endl;

        for (int j = 0; j <= number_of_unknown; ++j) {
            if (j == number_of_unknown) {
                cout << char(j + 97) << endl;
            } else if (j == number_of_unknown - 1) {
                cout << char(j + 97) << "x" << j + 1 << " = ";
            } else {
                cout << char(j + 97) << "x" << j + 1 << " + ";
            }
        }

        vector<double> co_efficient(number_of_unknown);
        for (int k = 0; k < number_of_unknown; ++k) {
            cin >> co_efficient[k];
        }
        cin>>c[i];
        if (co_efficient.size() != number_of_unknown and c[i]!=-1.0) {
            throw runtime_error("Input error!!!");
        }

        co_efficient_matrix.push_back(co_efficient);
    }

    return {co_efficient_matrix, c};
}
void Print1(vector<vector<double>>v)
{
    int i,j,k;

    cout<<setprecision(6)<<fixed;
    k=v[0].size()*16;
    cout<<" _"<<setw(k)<<"_ "<<endl;
    for(i=0;i<v.size();i++)
    {
        cout<<(i==v.size()-1?"|_":"| ");
        for(j=0;j<v[0].size();j++)
        {
            cout<<"\t"<<v[i][j]<<"\t";
        }cout<<(i==v.size()-1?"_|":" |")<<endl;
    }
    cout<<endl;
}
void Print2(vector<double>ans, char ch){

    for(int i=0; i<ans.size(); i++){
        cout<<ch<<i+1<<" = "<<ans[i]<<endl;
    }
    cout<<endl;
}
vector<double> back_substitution_upper(const vector<vector<double>>& co_efficient_matrix) {
    int n = co_efficient_matrix.size();
    vector<double> result(n, 0);

    for (int i = n - 1; i >= 0; --i) {
        double sum = 0;
        for (int j = n - 1; j > i; --j) {
            sum += co_efficient_matrix[i][j] * result[j];
        }
        result[i] = (co_efficient_matrix[i][n] - sum) / co_efficient_matrix[i][i];
    }

    return result;
}

vector<double> back_substitution_lower(const vector<vector<double>>& lower_matrix) {
    int n = lower_matrix.size();
    vector<double> result(n, 0);

    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < i; ++j) {
            sum += lower_matrix[i][j] * result[j];
        }
        result[i] = (lower_matrix[i][n] - sum) / lower_matrix[i][i];
    }

    return result;
}
pair<vector<vector<double>>, vector<vector<double>>> Find_LU(vector<vector<double>> matrix){
    int n=matrix.size();

    vector<vector<double>> Upper(n, vector<double>(n)), Lower(n, vector<double>(n));


    for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                Upper[i][j]=Lower[i][j]=matrix[i][j];
            }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j)Lower[i][j]=1;
            if(j>i)Lower[i][j]=0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            double multiplier=(Upper[j][i])/Upper[i][i];

            Lower[j][i]=multiplier;

            for(int k=i; k<n; k++){
                Upper[j][k]-=multiplier*Upper[i][k];
            }
        }
    }
    return {Lower, Upper};
}
vector<double>Solve_LU(vector<vector<double>> matrix, vector<double>c, vector<vector<double>>Lower, vector<vector<double>>Upper){

    vector<vector<double>>matrix_z, matrix_x;

    for(int i=0; i<c.size(); i++){
        vector<double>temp=Lower[i];
        temp.push_back(c[i]);
        matrix_z.push_back(temp);
    }

    cout<<"Lower Triangular matrix with C:\n";
    Print1(matrix_z);

    auto z=back_substitution_lower(matrix_z);
    cout<<"Values of Z:\n";
    Print2(z, 'Z');

    for(int i=0; i<z.size(); i++){
        vector<double>temp=Upper[i];
        temp.push_back(z[i]);
        matrix_x.push_back(temp);
    }

    cout<<"Upper Triangular Matrix with Z: \n";
    Print(matrix_x);

    return back_substitution_upper(matrix_x);

}
vector<vector<double>> find_inverse() {

    int n;
    cout << "Order of the square matrix for finding inverse: ";
    cin >> n;

    if (n < 1) {
        throw runtime_error("Invalid order!");
    }
    vector<vector<double>> matrix(n);

    for (int i = 0; i < n; ++i) {
        cout << "Please enter the row number " << i + 1 << ": ";
        matrix[i].resize(n);

        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }

        if (matrix[i].size() != n) {
            throw runtime_error("Input error!!!");
        }
    }
    vector<vector<double>>ans(n, vector<double>(n));


//    Print(matrix);

    auto itt=Find_LU(matrix);
    vector<vector<double>>Upper=itt.second, Lower=itt.first;

    for(int i=0; i<n; i++){
        vector<double>C(n, 0.0);
        C[i]=1.0;
        auto temp=Solve_LU(matrix, C, Lower, Upper);
        for(int j=0; j<temp.size(); j++){
            ans[j][i]=temp[j];
        }
    }
    return ans;
}
vector<double> SLE_solve(){

    auto it= Input();

    vector<vector<double>>matrix=it.first;
    vector<double>C=it.second;

    cout << "Entered coefficients:" << endl;
    Print1(matrix);

    cout<<"Values of c :"<<endl;
    Print2(C, 'C');

    auto itt=Find_LU(matrix);
    vector<vector<double>>Upper=itt.second, Lower=itt.first;

    cout<<"Upper triangular matrix: "<<endl;;
    Print1(Upper);

    cout<<"Lower triangular matrix: "<<endl;
    Print1(Lower);

    return Solve_LU(matrix, C, Lower, Upper);
}
int main() {
//
//    auto ans= find_inverse();
//    cout<<"Inverse of the given matrix is: \n";
//    Print1(ans);

    auto ans=SLE_solve();
    Print2(ans, 'X');
}

/*
25 5 1 106.8
64 8 1 177.2
144 12 1 279.2
*/

