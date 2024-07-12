#include <iostream> 
#include <string>

#include <vector> 
#include <functional> 

#include <map> 
#include <bitset> 

#include <fstream> 
using namespace std; 
/* Tạo một chương trình đơn giản yêu cầu người dùng nhập một mật khẩu và 
in ra thông báo nếu mật khẩu,username đúng hoặc sai.
*/
/* Kiểm tra mật khẩu bằng cách so sánh với một chuỗi đã mã hóa trong mã nguồn.
Tạo ra một bản mã nhị phân và thử nghiệm các kỹ thuật reverse engineering để tìm mật khẩu.
*/

// bước 1 // 
void hashing_password(); // mã hóa password // 
void hashing_username(); // mã hóa mật khẩu //

// bước 2 // 
void add_hash_password_firewall(hash <int> contain_hash_password); // tạo tường lửa cho password 
void add_hash_username_firewall(hash <string> contain_hash_username); // tạo tường lửa cho username // 

// bước 3 // 
void hacking_firewall_of_password(); // phá tường lửa của mật khẩu // 
void hacking_firewall_of_username(); // phá tường lửa của username // 

// bước 4 // 
void compare_hash_password(); // kiểm tra hash của mật khẩu // 
void compare_hash_username(); // kiểm tra hash của username // 

// bước 5 // 
void create_a_binary_file_for_password(); // tạo ra một bản mã nhị phân cho mật khẩu // 
void create_a_binary_file_for_username(); // tạo ra một bản mã nhị phân cho username // 


// tien hanh buoc dau tien // 
void hashing_username()
{
    cout <<"---Hashing username---" << endl; 

    string username_1 ;
    cout <<"Enter username 1 :" << endl; 
    getline(cin, username_1); 

    string username_2 ;
    cout <<"Enter username 2 :" << endl; 
    getline(cin,username_2);

    string username_3 ;
    cout <<"enter username 3:" << endl; 
    getline(cin, username_3); 

    string username_4 ;
    cout <<"Enter username 4:" << endl; 
    getline(cin,username_4);  

    hash <string> contain_hash_username;
    cout <<"The hash of the first username is:"<< contain_hash_username(username_1) << endl;  
    cout <<"the hash of the second username is:" << contain_hash_username(username_2) << endl; 
    cout <<"The hash of the third username is:" << contain_hash_username(username_3) << endl; 
    cout <<"the hash of the fourth username is:" << contain_hash_username(username_4) << endl; 
}
// tien hanh buoc dau tien // 
void hashing_password ()
{
    cout <<"---Hashing password---" << endl; 

    int password_1 ;
    cout <<"Enter the first password" << endl; 
    cin >> password_1; 

    int password_2 ; 
    cout <<"Enter the second password" << endl; 
    cin >> password_2;

    int password_3 ;
    cout <<"Enter the third password" << endl;
    cin >> password_3 ; 

    int password_4 ;
    cout <<"Enter the fourth password" << endl; 
    cin >> password_4;  

    hash<int> contain_hash_password; 
    cout <<"The hash of the first password is:" << contain_hash_password(password_1) << endl;
    cout <<"The hash of the second password is:" << contain_hash_password(password_2) << endl; 
    cout <<"The hash of the third passoword is:" << contain_hash_password(password_3) << endl; 
    cout <<"The hash of the fourth password is:" << contain_hash_password(password_4) << endl;  
}

// tiến hành bước thứ hai // 
void add_hash_password_firewall(hash <int>contain_hash_password)
{
    cout <<"Add hash password to firewall" << endl; 
    vector<hash<int>> add_hash_password; 
    add_hash_password.push_back(contain_hash_password); 

    // check the firewall inside // 
    for (const auto &hash : add_hash_password)
    {
        cout <<"The hash inside the firewall :" << &hash << endl; 
        for (const auto &integers : add_hash_password)
        {
            cout <<"The orginal content:" << &integers << endl; 
        }
    }
    if (false)
    {
        cout <<"The firewall is not completed." << endl; 
    }
    else 
    {
        cout <<"Continue to the firewall" << endl; 
    }
    cout << endl; 
}

// tien hanh buoc thu hai // 
void add_hash_username_firewall(hash <string> contain_hash_username)
{
    cout <<"add hash username" << endl; 
    vector <hash<string>> add_hash_username; 
    add_hash_username.push_back(contain_hash_username); 

    // check the firewall // 
    for (const auto &hash : add_hash_username)
    {
        cout <<"The hash inside the firewall:" <<&hash << endl;
        for (const auto &str : add_hash_username)
        {
            cout <<"The orginal content:" << &str << endl; 
        }
    }
    if (false)
    {
        cout <<"The firewall is not completed" << endl; 
    }
    else 
    {
        cout <<"Continue to keep the firewall safe" << endl; 
    }
    cout << endl; 
}

// tien hanh buoc thu ba // 
void hacking_firewall_of_password()
{
    /*trien khai tan cong brute force*/
    cout <<"--- Hello firewall. Nice to meet you ---" << endl; 
    vector<int> predict_password = {123, 456,789,1000};
    hash <int> contain_hash; 
    bool success = false; 
    for (const auto &decode : predict_password)
    {
        size_t hashed_function = contain_hash(decode); 
        cout <<"Trying to predict password:" << decode << "with hash :" << endl; 
        if (hashed_function == contain_hash(123))
        {
            success = true; 
            break; 
        }
    }
    if (success)
    {
        cout <<"Password firewall broken" << endl; 
    }
    else 
    {
        cout <<"failed to break the firewall"<< endl;
    }
}

void hacking_firewall_of_username()
{
    cout <<"-- hello username firewall--" << endl;
    vector<string>predict_username ={"abc", "befg", "gllk"}; 
    hash <string> contain_hash; 
    bool success_username = false; 

    for (const auto&decode : predict_username)
    {
        size_t hashed_function = contain_hash(decode); 
        cout <<"Trying to predict the username:" << decode << "with hash" << endl;
        if (hashed_function == contain_hash("abc"))
        {
            success_username = true; 
            break; 
        }
    }
    if (success_username)
    {
        cout <<"The firewall username is broke" << endl; 
    }
    else 
    {
        cout <<"Failed to break the firewall" << endl; 
    }
    cout << endl; 
}

void compare_hash_username()
{
    cout <<"compare hash username" << endl; 
    hash<string> compare_username; 
    vector<hash<string>> checking_username; 
    checking_username.push_back(compare_username);
    for (int i = 0 ; i < checking_username.size(); i++)
    {
        checking_username[i]; 
        for (int j = 0 ; i = j + 1; j++)
        {
            checking_username[j+1] = checking_username[i]; 
        }
        cout <<"The size of checking username is :" << checking_username.max_size() << endl; 
    }
    while (!checking_username.empty())
    {
        cout <<"Continue" << endl; 
        if (checking_username.size() == compare_username("abc"))
        {
            cout <<"The hacker found the hash, god access." << endl;
            if (checking_username.size() == compare_username(""))
            {
                cout <<"This is user so special. Keep find the worst in them" << endl; 
            } 
        }
        else 
        {
            cout <<"Something scratching out a part of my mind." << endl; 
        }
    }
    if (false)
    {
        cout <<"The comparison of username has not been created" << endl; 
    }
    else 
    {
        cout <<"error" << endl; 
    }
    cout << endl; 
}

void compare_hash_password()
{
    cout <<"compare hash password for Mr Robot" << endl; 
    hash<int> compare_password; 
    vector<hash<int>> checking_password; 
    checking_password.push_back(compare_password);
    for (int i = 0 ; i < checking_password.size(); i++)
    {
        checking_password[i]; 
        for (int j = 0 ; i = j + 1; j++)
        {
            checking_password[j+1] = checking_password[i]; 
        }
        cout <<"The size of checking password is :" << checking_password.max_size() << endl; 
    }
    while (!checking_password.empty())
    {
        cout <<"Continue" << endl; 
        if (checking_password.size() == compare_password(100))
        {
            cout <<"The hacker found the hash, god access." << endl;
            if (checking_password.size() == compare_password(200))
            {
                cout <<"This is user so special. Keep find the worst in them" << endl; 
            } 
        }
        else 
        {
            cout <<"Something scratching out a part of my mind." << endl; 
        }
    }
    if (false)
    {
        cout <<"The comparison of password has not been created" << endl; 
    }
    else 
    {
        cout <<"error" << endl; 
    }
    cout << endl; 
}

void create_a_binary_file_for_password() 
{
    string password = "my_secret_password";
    ofstream outFile("password.bin", std::ios::binary);
    if (outFile) 
    {
        outFile.write(password.c_str(), password.size());
        outFile.close();
        cout << "Password binary file created successfully.\n";
    } 
    else 
    {
        cerr << "Error creating password binary file.\n";
    }
}

// Hàm tạo file nhị phân cho tên người dùng
void create_a_binary_file_for_username() 
{
    string username = "my_username";
    ofstream outFile("username.bin", std::ios::binary);
    if (outFile) 
    {
        outFile.write(username.c_str(), username.size());
        outFile.close();
        cout << "Username binary file created successfully.\n";
    } 
    else 
    {
        cerr << "Error creating username binary file.\n";
    }
}
int main ()
{
    while (true)
    {
        cout <<"--- Hello, Friend ---" << endl;
        cout <<"----Your privacy has been hacked, never gets old---" << endl; 

        cout <<"__step 1_" << endl; 
        cout <<"First function :" <<"hashing_passsword()" << endl; 
        cout <<"Second function:" <<"hashing username() " << endl ;

        cout <<"__step 2__" << endl; 
        cout <<"Third function:" << "add_hash_password_firewall()" << endl; 
        cout <<"Fourth function:" <<" add_hash_username_firewall()" << endl; 

        cout <<"__step 3__" << endl; 
        cout <<"Five function:" <<"break_the password_firewall()"<< endl;
        cout <<"Six function:" <<"break_the username_firewall()" << endl; 

        cout <<"__step 4__" << endl; 
        cout <<"Seven function:" <<"compare hash_username()" << endl; 
        cout <<"eight function :" <<"compare hash password()" << endl;

        cout <<"__step 5__" << endl; 
        cout <<"ninth function" << "create a binary file for username" << endl; 
        cout <<"10th function" <<"create a binary file for password" << endl; 

hashing_password(); 
hashing_username(); 

// bước 2 // 
hash<int> contain_hash; 
hash<string> contain_hash_username; 
add_hash_password_firewall(contain_hash);  
add_hash_username_firewall(contain_hash_username); 

// bước 3 // 
hacking_firewall_of_password();  
hacking_firewall_of_username();  

// bước 4 // 
compare_hash_password(); 
compare_hash_username(); 

// bước 5 // 
    int choices; 
    cout <<"let see your choices" << endl; 
    cin >> choices; 
    while (cin.good())
    {
    create_a_binary_file_for_password(); 
    create_a_binary_file_for_username();
    break; 
    }
    cout << endl; 
    break; 
    }
    return 0 ;
}