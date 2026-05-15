#include <iostream>

        int state = 0;

        for(char c : input) {

            switch(state) {

                case 0:
                    if(isdigit(c))
                        state = 1;
                    else
                        return false;
                    break;

                case 1:
                    if(isdigit(c))
                        state = 1;
                    else if(c == '.')
                        state = 2;
                    else
                        return false;
                    break;

                case 2:
                    if(isdigit(c))
                        state = 3;
                    else
                        return false;
                    break;

                case 3:
                    if(isdigit(c))
                        state = 3;
                    else
                        return false;
                    break;
            }
        }

        return (state == 1 || state == 3);
    }
};

int main() {

    FSA automata;

    string input;

    cout << "Enter number: ";
    cin >> input;

    if(automata.validateNumber(input)) {
        cout << "Valid number" << endl;
    }
    else {
        cout << "Invalid number" << endl;
    }

    return 0;
}
