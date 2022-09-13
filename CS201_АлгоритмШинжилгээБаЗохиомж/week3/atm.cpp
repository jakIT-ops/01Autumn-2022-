#include <iostream>
using namespace std;

int pinNumber = 1234;
int AccountBalance = 0;

bool checkPassword() {

    int InputPinNumber = -1;
    bool isPinInvalid = true;

    while (isPinInvalid) {
        cout << "Пин кодоо оруулна уу!: ";
        cin >> InputPinNumber;

        if (InputPinNumber == pinNumber) {
            isPinInvalid = false;
        }
        else {
            cout << "Пин код буруу байна дахин оруулна уу " << endl;
        }

    }
    return true;
}

int DisplayMenu() {

    int UserInputOption = -1;

    cout << "Доорх сонголтуудаас хийнэ үү!" << endl;
    cout << "    1 - Дансны үлдэгдэл харах" << endl;
    cout << "    2 - Зарлага гаргах" << endl;
    cout << "    3 - Оролого хийх" << endl;
    cout << "    4 - Гарах" << endl;
    cin >> UserInputOption;

    return UserInputOption;

}

void DisplayAccountBalance() {
    cout << "Таны дансны үлдэгдэл: " << endl;
    cout << AccountBalance << "₮" << endl;
}

void WithDrawMoneyFromAccount() {

    int UserInputOption = -1;
    int valueToWithdraw = 0;
    long CustomerRequest = 0;
    bool isNotFinished = true;

    do {

        cout << "Зарлагын сонголтууд:" << endl;
        cout << "1 - 5000₮" << endl;
        cout << "2 - 10000₮" << endl;
        cout << "3 - 20000₮" << endl;
        cout << "4 - Өөрийн хүссэн дүнгээр" << endl;
        cout << "5 - Гүйлгээ цуцлах" << endl;

        cin >> UserInputOption;
        switch (UserInputOption) {
            case 1:
                valueToWithdraw = 5000;
                break;
            case 2:
                valueToWithdraw = 10000;
                break;
            case 3:
                valueToWithdraw = 20000;
                break;
            case 4:
                cout << "Дүнгээ оруулна уу:" << endl;
                cin >> CustomerRequest;
                valueToWithdraw = CustomerRequest;
                isNotFinished = false;
                break;
            case 5:
                isNotFinished = false;
                break;
        }

        if (valueToWithdraw != 0) {
            if (valueToWithdraw > AccountBalance) {
                cout << "Дансны үлдэгдэл хүрэлцэхгүй байна: " << AccountBalance << ". Гүйлгээ цуцлагдалаа" << endl;
            }
            else {
                AccountBalance = AccountBalance - valueToWithdraw;
                isNotFinished = false;
            }
            valueToWithdraw = 0;
        }

    } while (isNotFinished);

}

void DepositMoneyInAccount() {

    int UserInputOption = -1;
    bool isNotFinished = true;
    long depositAmount = 0;

    do {

        cout << "Доорх сонголтоос сонгоно уу" << endl;
        cout << "1 - 5000₮" << endl;
        cout << "2 - 10000₮" << endl;
        cout << "3 - 20000₮" << endl;
        cout << "4 - Өөрийн хүссэн дүнгээр" << endl;
        cout << "5 - Гүйлгээ цуцлах" << endl;

        cin >> UserInputOption;
        switch (UserInputOption) {
            case 1:
                AccountBalance = AccountBalance + 5000;
                isNotFinished = false;
                break;
            case 2:
                AccountBalance = AccountBalance + 10000;
                isNotFinished = false;
                break;
            case 3:
                AccountBalance = AccountBalance + 20000;
                isNotFinished = false;
                break;
            case 4:
                cout << "Дүнгээ оруулна уу:" << endl;
                cin >> depositAmount;
                AccountBalance = AccountBalance + depositAmount;
                isNotFinished = false;
                break;
            case 5:
                isNotFinished = false;
                break;
        }

    } while (isNotFinished);

}

int main() {

    if (checkPassword()) {
        int opt = -1;
        int isNotFinished = true;

        do {

            switch (DisplayMenu()) {
                case 1:
                    DisplayAccountBalance();
                    cout << "Доорх сонголтоос сонгоно уу" << endl;
                    cout << "1 - Үргэжилүүлэх үү!" << endl;
                    cout << "2 - Картаа авах" << endl;
                    cin>>opt;
                    if (opt == 1){
                        checkPassword();
                    }else {
                        isNotFinished = false;
                    }
                    break;
                case 2:
                    WithDrawMoneyFromAccount();
                    cout << "Доорх сонголтоос сонгоно уу" << endl;
                    cout << "1 - Үргэлжилүүлэх үү!" << endl;
                    cout << "2 - Картаа авах" << endl;
                    cin>>opt;
                    if (opt == 1){
                        checkPassword();
                    }else {
                        isNotFinished = false;
                    }
                    break;
                case 3:
                    DepositMoneyInAccount();
                    cout << "Доорх сонголтоос сонгоно уу" << endl;
                    cout << "1 - Үргэжилүүлэх үү!" << endl;
                    cout << "2 - Картаа авах" << endl;
                    cin>>opt;
                    if (opt == 1){
                        checkPassword();
                    }else {
                        isNotFinished = false;
                    }
                    break;
                case 4:
                    isNotFinished = false;
                    break;
                default:
                    cout << "Буруу сонголт дахин орлдоно уу." << endl;
                    break;
            }

        } while (isNotFinished);
    }
    return 0;

}
